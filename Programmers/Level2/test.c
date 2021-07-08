char pw[100];


 printf("Enter your password: ");
 scanf("%[^,\t\n]", pw);  // 쉼표, 탭, 엔터를 만나면 종료
// %[^\t\n] //탭이나 엔터키 만나면 종료 
// %[^\0] //문장끝만나면 종료