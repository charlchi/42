.name "zork"
.comment "just a basic living prog"
		
0	l2:	sti	r1, [2] ,%0
1	and	r1,%0,r1

2 	live:	live	%1
3	zjmp	%:live


0 add
1 zjmp 4
2
3
4 myfunction
5
6
7
