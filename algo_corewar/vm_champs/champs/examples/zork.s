.name "zork"
.comment "I'M ALIIIIVE"

l2:		zjmp %:live

live:	live %1
		zjmp %:live
