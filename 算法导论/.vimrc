syntax on
	set tabstop=4
    set softtabstop=4
    set shiftwidth=4 
	set autoindent
    set cindent
    set cinoptions={0,1s,t0,n-2,p2s,(03s,=.5s,>1s,=1s,:1s 
	set nu
	filetype plugin indent on
	set completeopt=longest,menu
	set ruler
	set foldenable   
	set foldmethod=manual 
	set completeopt=preview,menu
	set number
	set hlsearch
	set incsearch
	set showmatch 
	set tags=tags
	inoremap ( ()<ESC>i
	inoremap [ []<ESC>i
	inoremap " ""<ESC>i
	inoremap ' ''<ESC>i
	inoremap { {<CR>}<ESC>ka<CR>	
if &term=="xterm"
	set t_Co=8
 	set t_Sb=^[[4%dm
    set t_Sf=^[[3%dm
endif
