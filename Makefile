# build:
# 	g++ -Wall -Weffc++ -pedantic -pedantic-errors -Wextra -Wcast-align -Wcast-qual -Wconversion -Wdisabled-optimization -Wfloat-equal -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimport  -Winit-self  -Winline -Winvalid-pch  -Wmissing-field-initializers -Wmissing-format-attribute  -Wmissing-include-dirs -Wmissing-noreturn -Wno-sign-conversion -Wpacked  -Wpointer-arith -Wredundant-decls -Wshadow -Wstack-protector -Wstrict-aliasing=2 -Wswitch-default -Wswitch-enum -Wunreachable-code -Wunused -Wunused-but-set-variable -Wunused-parameter -Wvariadic-macros -Wwrite-strings *.h *.cpp -g 
# build:
# 	g++ -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g *.cpp *.h -w
build:
	icc *.cpp -g -O3 -qopenmp -axCORE-AVX2
#	g++ -g -O0 *.cpp
