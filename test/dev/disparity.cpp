#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char * argv[] ){

        FileStorage fs("intrinsics.yml",FileStorage::READ);
        
        Mat M1,M2,D1,D2;
        fs["M2"]>>M2;
        fs["M1"]>>M1;
        fs["D1"]>>D1;
        fs["D2"]>>D2;

        fs.release();

        FileStorage fs2("extrinsics.yml",FileStorage::READ);
        
        Mat Q;
        fs2["Q"]>>Q;

        fs2.release();

        cout << "M1:" << M1 << endl;
        cout << "M2:" << M2 << endl;
        cout << "D1:" << D1 << endl;
        cout << "D2:" << D2 << endl;
        cout << "Q:" << Q << endl;

        //-- 1. Read the images
        Mat imgLeft = imread( argv[1], IMREAD_GRAYSCALE );
        Mat imgRight = imread( argv[2], IMREAD_GRAYSCALE );
        //-- And create the image in which we will save our disparities
        Mat imgDisparity16S = Mat( imgLeft.rows, imgLeft.cols, CV_16S );
        Mat imgDisparity8U = Mat( imgLeft.rows, imgLeft.cols, CV_8UC1 );

       
        if( !imgLeft.data || !imgRight.data )
        { std::cout<< " --(!) Error reading images " << std::endl; return -1; }

        //-- 2. Call the constructor for StereoBM
        int ndisparities = 16*1;//5   /**< Range of disparity */
        int SADWindowSize = 5; //21 /**< Size of the block window. Must be odd */

        Ptr<StereoBM> sbm = StereoBM::create( ndisparities, SADWindowSize );

        //-- 3. Calculate the disparity image
        sbm->compute( imgLeft, imgRight, imgDisparity16S );

        //-- Check its extreme values
        double minVal; double maxVal;

        minMaxLoc( imgDisparity16S, &minVal, &maxVal );

        printf("Min disp: %f Max value: %f \n", minVal, maxVal);

        //-- 4. Display it as a CV_8UC1 image
        imgDisparity16S.convertTo( imgDisparity8U, CV_8UC1, 255/(maxVal - minVal));
        Mat _3dImage; 
        bool handleMissingValues;
        int ddepth;

        reprojectImageTo3D(imgDisparity8U, _3dImage, Q, handleMissingValues=false, ddepth=-1 );
         
        imshow("test",_3dImage);     
        waitKey(0); 
        
        return 0;
}
