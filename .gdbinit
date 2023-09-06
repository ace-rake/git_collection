define follow
	set follow-fork-mode $arg0
end
document follow
set follow-fork-mode $arg0
end

define frin
	info locals
	info args
end
document frin
info frame
print the local and argument variables of current frame
end

define f
	finish
end
document f
finnish current function
end

define c
	continue
	info locals
	info args
end
document c
continue, info locals, info args
end

define btf
	bt -full
end
document btf
gives the current backtrace with all variables in each function call
end

define ibp
	info breakpoints
end
document ibp
info breakpoints
end

define rel
	source .gdbinit
end
document rel
reload local .gdbinit file
end


define re
	source ~/.gdbinit
end
document re
reload ~/.gdbinit file
end
