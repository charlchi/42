
if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall
endif

call plug#begin('~/.vim/plugged')

Plug 'VundleVim/Vundle.vim'
Plug 'airblade/vim-gitgutter'
Plug 'editorconfig/editorconfig-vim'
Plug 'itchyny/lightline.vim'
Plug 'junegunn/fzf'
Plug 'junegunn/fzf.vim'
Plug 'mattn/emmet-vim'
Plug 'scrooloose/nerdtree', {'on': 'NERDTreeToggle'}
Plug 'terryma/vim-multiple-cursors'
Plug 'tpope/vim-eunuch'
Plug 'tpope/vim-surround'
Plug 'w0rp/ale'

call plug#end()


map <C-o> :NERDTreeToggle<CR>


hi MatchParen term=underline cterm=underline,bold ctermfg=white ctermbg=none

colorscheme default
syntax on
set encoding=utf-8
set fileencoding=utf-8
set fileencodings=utf-8
set bomb
set wildmenu
set binary
set tabstop=4
set softtabstop=0
set shiftwidth=4
set hlsearch
set incsearch
set ignorecase
set smartcase
set nobackup
set noswapfile
set ruler
set backspace=indent,eol,start
set number relativenumber
set t_Co=256
set laststatus=2
set modeline
set modelines=10
set title
set titleold="Terminal"
set titlestring=%F
set statusline=%F%m%r%h%w%=(%{&ff}/%Y)\ (line\ %l\/%L,\ col\ %c)\
set termguicolors
set guicursor=n-v-c-sm:block,i-ci-ve:ver25,r-cr-o:hor20
set clipboard+=unnamedplus
set noshowmatch
let loaded_matchparen=1
