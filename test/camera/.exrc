if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <Plug>(neocomplcache_start_omni_complete) 
inoremap <silent> <Plug>(neocomplcache_start_auto_complete_no_select) 
inoremap <silent> <Plug>(neocomplcache_start_auto_complete) =neocomplcache#mappings#popup_post()
inoremap <silent> <expr> <Plug>(neocomplcache_start_unite_quick_match) unite#sources#neocomplcache#start_quick_match()
inoremap <silent> <expr> <Plug>(neocomplcache_start_unite_complete) unite#sources#neocomplcache#start_complete()
imap <Nul> <C-Space>
inoremap <silent> <expr> <Plug>delimitMateS-BS delimitMate#WithinEmptyPair() ? "\<Del>" : "\<S-BS>"
inoremap <silent> <Plug>delimitMateBS =delimitMate#BS()
nnoremap \d :YcmShowDetailedDiagnostic
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
nnoremap <SNR>68_: :=v:count ? v:count : ''
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
nnoremap <C-Left> :bprev			" Re-map la commande :bprev avec le combo CTRL+flecheGauche
nnoremap <C-Right> :bnext			" Re-map la commande :bnext avec le combo CTRL+flecheDroite
let &cpo=s:cpo_save
unlet s:cpo_save
set autoread
set background=dark
set backspace=indent,eol,start
set backupdir=~/.vim/backup_files//
set completefunc=neocomplcache#complete#manual_complete
set completeopt=preview,menuone
set cpoptions=aAceFsB
set directory=~/.vim/swap_files//
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=fr
set hidden
set history=1000
set laststatus=2
set mouse=a
set printoptions=paper:a4
set ruler
set runtimepath=~/.vim,~/.vim/bundle/Vundle.vim,~/.vim/bundle/lightline.vim,~/.vim/bundle/vim-gitbranch,~/.vim/bundle/nerdtree,~/.vim/bundle/vim-fugitive,~/.vim/bundle/YouCompleteMe,~/.vim/bundle/delimitmate,~/.vim/bundle/neocomplcache.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim80,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after,~/.vim/bundle/Vundle.vim,~/.vim/bundle/Vundle.vim/after,~/.vim/bundle/lightline.vim/after,~/.vim/bundle/vim-gitbranch/after,~/.vim/bundle/nerdtree/after,~/.vim/bundle/vim-fugitive/after,~/.vim/bundle/YouCompleteMe/after,~/.vim/bundle/delimitmate/after,~/.vim/bundle/neocomplcache.vim/after
set scrolloff=5
set shortmess=filnxtToOc
set showcmd
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabline=%!lightline#tabline()
set wildmenu
set wildmode=longest:full,full
set nowritebackup
" vim: set ft=vim :
