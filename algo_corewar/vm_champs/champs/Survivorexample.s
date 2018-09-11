.name    "Survivor"
.comment "Invincible"

0	live	%1
1	fork	%:f1
2	zjmp	%:j1
<<<<<<< .mine
3  f1:	ld	%5, r2
=======
4 f1:	ld	%4, r2
>>>>>>> .r20
	zjmp	%:run
j1:	
run:	xor	r0, r0, r0
l1:	st	r2, 1
	live	%1
	zjmp	%:l1






