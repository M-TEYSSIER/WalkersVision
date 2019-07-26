#include <iostream>
#include<time.h>
#include <opencv2/opencv.hpp>
#include <iomanip>



int main(int argc, char* argv[]) {

    std::cout << "Calibrating a camera using OpenCV." << std::endl;
	
    cv::VideoCapture camera(atoi(argv[1]));

    if(!camera.isOpened()) {
        std::cout << "Camera could not be opened." << std::endl;
    }

    cv::Mat frame, working_frame,working_frame_old;
    cv::Size frame_size;
	cv::Size working_frame_size (640, 480);

    cv::namedWindow("Working Frame");
  
    int board_width = 7;      // number of inner chessboard cornears 
    int board_height = 7;
    int number_of_boards = board_width * board_height;
    cv::Size board_size (board_width, board_height);

    int number_of_images = 10;

    std::vector<std::vector<cv::Point2f>> image_points;
    std::vector<std::vector<cv::Point3f>> object_points;
    
    double last_captured_timestamp = 0;

	while( image_points.size() < static_cast<size_t>(number_of_images) ) {

        camera >> frame;
        if(frame.empty()) {
            continue;
        }
    
        frame_size = frame.size();
        cv::resize(frame, working_frame, working_frame_size);
 
        std::vector<cv::Point2f> corners;
        bool found = cv::findChessboardCorners(working_frame, board_size, corners);
		
        working_frame.copyTo(working_frame_old);//just copy the frame to save it when found true.
		
		
        cv::drawChessboardCorners(working_frame, board_size, corners, found);
		
        double timestamp = static_cast<double>((clock())/CLOCKS_PER_SEC);

        if(found && timestamp - last_captured_timestamp > 1) {
			    
			
			std::stringstream Frame;   // name used to save chapture images
	       Frame << "Frame" << std::setw(2) << std::setfill('0') << image_points.size() << ".jpg";		
	       cv::imwrite(Frame.str(), working_frame_old);

            last_captured_timestamp = timestamp;
            working_frame ^= cv::Scalar::all(255);
           
            image_points.push_back(corners);
            object_points.push_back(std::vector<cv::Point3f>());
			
            std::vector<cv::Point3f>& opts = object_points.back();
            opts.resize(number_of_boards);
            for (int j=0; j<number_of_boards; j++) {
                opts[j] = cv::Point3f(static_cast<float>(j/board_width), static_cast<float>(j%board_width), static_cast<float>(0));
            }            

        }

        cv::imshow("Working Frame", working_frame);

        char c;
        c = cv::waitKey(1);
        if(c == 'q') {
            break;
        }

    }
   
    cv::Mat intrinsic_matrix, distortion_coefficients;

    double reprojection_error = cv::calibrateCamera(
        object_points,
        image_points,
        frame_size,
        intrinsic_matrix,
        distortion_coefficients,
        cv::noArray(),
        cv::noArray(),
        cv::CALIB_ZERO_TANGENT_DIST | cv::CALIB_FIX_PRINCIPAL_POINT
    );
   
    std::string path = "./default.xml";
    cv::FileStorage fs;

    std::cout << "Reprojection error is: " << reprojection_error << std::endl;
    
    fs.open(path, cv::FileStorage::WRITE);

    fs << "intrinsic_matrix" << intrinsic_matrix;
    fs << "distortion_coefficients" << distortion_coefficients;
    fs << "reprojection_error" << reprojection_error;
  
    fs.release();
    
    cv::destroyAllWindows();

    std::cout << "Done." << std::endl;

    return 0;
}
