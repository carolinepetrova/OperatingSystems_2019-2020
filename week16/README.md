# Задачи върху програми на С - втора част 

1.  Да се напише програма на C, която реализира `head f1` - извежда първите 10 реда от съдържанието на f1 на стандартния изход. 
2.  Да се напише програма на С, която получава като параметър име на файл. Ако файлът не съществува се създава, а ако същестува се изтрива съдържанието му. Програмата чете редове от стандартния вход, заменя всяка цифра с * и записва реда във файла. 
3.  Да се напише програма на C, която извежда номера на процеса и номера на родителя му. Сменя образа му с UNIX команда (например ps) и извежда резултата от exec().
4.  Да се напише програма на С, която получава като параметър име на файл. Създава процес син, който записва стринга `foobar` във файла (ако не съществува, го създава, в противен случай го занулява), след което процеса родител прочита записаното във файла съдържание и го извежда на стандартния изход, добавяйки по един интервал между всеки два символа.