# Условия и цикли

## Командата test
Синтаксис: `test <израз>`

Особености: 

- командата не връща нищо, но има код на изход: 

	- 0: истина (тестът е бил успешен)

	- 1: лъжа (тестът е бил неуспешен)

	- 2: синтактична грешка

- взимаме кода чрез $? 

 - за сравняване на стойности главно се използват **опции**, а за низове се използват **oператори**

### Оператори и опции, които се използват за сравнения: 

| Сравняване за цели числа | Функция   |
|--|--|
| -gt (greater than) | по-голямо от |
| -lt (less than) | по-малко от |
| -ge (greater or equal) | по-голямо или равно |
| -le (less or equal) | по-малко или равно |
| -eq (equal) | равно |
| -ne (not equal) | неравно |

| Сравняване на низове | Функция  |
|--|--|
| -z | проверява за празен низ |
| -n | проверява за непразен низ |
| = | равни низове |
| != | различни низове |
| < и > | сравнява лексикографски низовете |

| Проверки за файлове   | Функция  |
|--|--|
| -f | файлът съществува |
| -s | файлът не е празен |
| -d | файлът е директория |
| -r | файлът може да се чете |
| -w | във файлът може да се записва |
| -x | файлът може да се изпълнява |

| Логически оператор   | Функция  |
|--|--|
| ! | логическо отрицание |
| -а | логическо И |
| -o | логическо ИЛИ |


**Пример:**
```
$ test value1 -option value2  
$ test string operator string
```

**За по-четлив и прост запис вместо командата test може да се използват квадратните скоби ([ ]).**


**Пример:**
```
$ [value1 -option value2]
$ [string operator string]
```

## Условен оператор if

**Синтаксис:**
```
if команда then
действие (команда 2)
[elif 
команда3 
then
команда4]
...
[else 
командаN]
fi
```
**Пример:**
```
file=/etc/passwd
if grep Georgi $file 
then
echo "There are names containing Georgi in $file"
else 
echo "No matches were found"
fi
```
```
read num1 num2
if [ $num1 -eq $num2 ]
then
echo "Numbers from stdin are equal"
elif  [ $num1 -lt $num2 ]
then
echo " $num1 < $num2 "
else 
echo " $num1 > $num2 "
fi
```

## Оператор за избор case

**Синтаксис:**

```
case стойност in  
шаблон1 | шаблон2 | ...) 
команда
;;  
[…]  
esac
```

**Пример:**

Създаване на командна процедура, която по подадено име на държава от стандартния изход, дава информация, кой е официалният език на държавата.
```sh
read country
case $country in 
USA | UK | Australia )
echo "The official language of $country is English"
;;
Romania | Moldova)
echo "The official language of $country is Romanian"
;;
China)
echo "The official language of China is Mandarin"
*)
echo "We don't have data about $country
;;
esac
```

## Цикли

### while цикъл 

**Синтаксис:**
```sh
while условие(команда)
do
   команда1 
   команда2
   команда3
   ...
done
```

Пример:
```sh 
x=0
while [ $x -le 5 ]
do
echo $x
x=$(expr $x + 1)
done
```
### until цикъл 
**Синтаксис:**
```sh
until условие(команда)
do
   команда1 
   команда2
   команда3
   ...
done
```
**Пример:**
```
read user
until who | grep $user 
do
echo "Waiting for user $user to login"
sleep 10
done
```
### for цикъл

**Синтаксис:**
```
for променлива in [списък]
do 
команда1
команда2
...
done
```

**Примери:**
```
for i in 1 2 3 4 5
do 
echo $i
done
```
Изход:

1
2
3
4
5

```
read user1 user2 user3
file=/etc/passwd
for user in $user1 $user2 $user3
write $user < $file
done
```
Изход: изпраща съдържанието на файла /etc/passwd на потребителите, прочетени от стандартния вход

```
x=1
for args in $@
echo "command line argument $x is $args"
x=$(expr $x + 1)
done
```
Изход: принтира на стандартния изход позиционните параметри подадени на командната процедура

## break и continue

### break [n]
- Прекъсва n-тият цикъл отвътре-навън

- ако не е зададен n то се прекъсва цикъла, в който е сложен break

### continue [n]

- skip-ват се всички команди след него и се продължава с n итерации напред 

- ако не е зададен n то се продължава с 1 итерация напред