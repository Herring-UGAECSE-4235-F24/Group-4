run: I2C_Driver
	./I2C_Driver

I2C_Driver: clean
	gcc -o I2C_Driver I2C_Driver.c -lc E4235_Read.s E4235_Select.s E4235_Delaymilli.s
	
	
clean:
	rm -f I2C_Driver
