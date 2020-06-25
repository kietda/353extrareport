# 353extrareport
The png file above is my system info (systeminfo.png). My OS is Ubuntu 20.04. I use Visual Studio Code to write code, but I use terminal to compile and run them. 
I tried these following steps for this assignment:
1. I use the list of words downloaded from voronoi server (web2) to create a new list without capitcal letters (web4).
2. I created text file (a rainbow table) from web4 (foo4.c) and searched that file, and didn't get any result.
3. I created a function to capitalize every word in list (web4). For example, if a word has 8 characters length, the total I will have is 2^8 (256). Then I use them to generate a new rainbow table. The file "foo7.c" did that, and the run time is 8 mintues 40 seconds.
(runtime.png)
Use vi to search the table, I got 2 passwords:
namenta:Db2zVoF2IGSDw:6602:6602:des_users:0:0:Nina Amenta:/home/namenta:/bin/csh
	>>GeoMetrY|rDIWg8nR.laZQ|fTAppo85O4UC2|Db2zVoF2IGSDw|kvWKo4sXN0XLw|tBvw3PqybWk.2
mdicaza:tBZxqSZYrsjS2:6604:6604:des_users:0:0:Miguel de Icaza:/home/mdicaza:/bin/csh
	>>GNOME|rDd5myCR6S2H2|fT0S96JKQm3Qk|DbaxMTsYYC/Wc|kviItT2S4vAr2|tBZxqSZYrsjS2

4. Now I only have 3 unknown passwords. This time, I generate a full list of 5-characters words (foo1.c), and compare with the list of hashes. I found one, but this is the password I had found before (GNOME)
Then, I tried on generating words with different length (4,3,2,1), and I got one more:
lconway:fTz5hLJSTAdlM:6601:6601:des_users:0:0:Lyn Conway:/home/lconway:/bin/csh
	>>vlsi:fTz5hLJSTAdlM	
5. I seperate the list of words from web4 into 8 lists. Every list will have different length (from 1 to 8 characters long). Then I multiply them together to create a new list of word. I used file foo8.c.
For 8-characters password, I will have 1x7,2x6,3x5,4x4 double-words. 
For 7-characters password, I will have 1x6, 2x5, 3x4 double-words.
For 6-characters password, I will have 1x5,2x4,3x3 double-words. This time, I found the fourth password:
jlawson:rDm4EJS49RZ3o:6600:6600:des_users:0:0:Jerry Lawson:/home/jlawson:/bin/csh
	>>foobar|rDm4EJS49RZ3o|fT3K12GEwcqrA|kvNm04WdaWRMg
I stopped here, because I already check all cases of 5-characters passwords above.

6. Finally, I try others ways, like reverse the order of words, use a list of words downloaded from internet, or combine step 3 and step 5 together, but I can't succeed to find the last one.




