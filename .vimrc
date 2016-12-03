set autoindent 
set ts=2
set number
" au BufNewFile *.cpp 0r ~/Templates/template.cpp 
au BufNewFile *.cpp 0r ~/Documents/Competitive-Programming/Template\ Archive/template/main.cpp
au BufNewFile *.java 0r ~/Documents/Competitive-Programming/Template\ Archive/template/main.java
au BufNewFile *.py 0r ~/Documents/Competitive-Programming/Template\ Archive/template/main.py


inoremap jkl <ESC>
inoremap jj <ESC>
hi Comment cterm=NONE ctermfg=red ctermbg=NONE
set noswapfile
set sw=2
