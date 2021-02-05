info=input()
str1=info.upper()
for i in range(26):
    print("%c |"%chr(i+65), "*"*str1.count(chr(i+65)))
