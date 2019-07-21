
all:
	make -C src/asm/
	make -C src/vm/

clean:
	make clean -C src/asm/
	make clean -C src/vm/

fclean: clean
	make fclean -C src/asm/
	make fclean -C src/vm/

re: fclean all