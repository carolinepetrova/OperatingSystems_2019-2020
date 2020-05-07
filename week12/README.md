
# Системни примитиви за работа с процеси

Инстанция на работеща програма се нарича **процес.**  Процесите могат да създават други процеси, като оригиналният процес се нарича **родител**, а новосъздадения се нарича **дете**.Един родител може да има много процеси-деца, но едно дете може да има най-много един родител.  По този начин се създават йерархични групи от процеси, които могат да комуникират помежду си и да споделят ресурси.

![enter image description here](https://i.stack.imgur.com/DfzHf.png)

## Създаване на процес-дете
```C
#include <sys/types.h>  
#include <unistd.h>  
pid_t fork(void);
```
След изпълняване на **fork()** вече имаме два процеса - съществуващия (създал детето) се нарича родител, а новосъздадения е процесът-дете. 

**fork() връща:**

-  -1 при неуспешно създаване на процес-дете

- 0 за процес-дете
 
- pid-то на новосъздадения процес-дете


Новосъздадения процес е почти точно копие на родителя си. След като сме изпълнили **fork()** от тук-насетне всичкия код, който сме написали се изпълнява и от родителя и от детето. 

**Пример:**
```C
#include  <stdio.h> 
#include  <sys/types.h>  
#include  <unistd.h>  
int main() { 
	printf("Hello there!");
	fork(); 
	printf("Called fork()");  
	return  0; 
}
```
**Изход:** ???

**Кой се изпълнява първи - родителя или детето?**

Всеки път различно - и двата процеса работят **асинхронно**.

**Как да направим така, че да има код, който ще се изпълни само от родителя/детето?**

Използваме резултатът от fork().

```C
#include  <stdio.h> 
#include  <sys/types.h>  
#include  <unistd.h>  
int main() {
	int pid = fork(); 
	if(pid == -1) {
		perror("Couldn't fork!);
		exit(-1);
	}
	else if(pid > 0) {
		//this is the only parent part
		printf("Hello from the parent");
	}
	else {
		//this is the only child part
		printf("Hello from the child");
	}
	printf("Called fork()");  
	return  0; 
}
```

**Примерен изход:**
```
Hello from the parent
Called fork()
Hello from the child
Called fork()
```

### Пример: Споделени ресурси
```C
#include  <stdio.h> 
#include  <sys/types.h>  
#include  <unistd.h>  
int main() {
	int a = 1;
	int pid = fork(); 
	if(pid == -1) {
		perror("Couldn't fork!");
		exit(-1);
	}
	else if(pid > 0) {
		++a;
	}
	else {
		--a;
	}
	printf("a=%d\n",a);  
	return  0; 
}
```

**Изход:** ??? 

### Получаване на pid за процесът-дете и процесът-родител

```C
#include <sys/types.h>  
#include <unistd.h>  
pid_t getpid(void);
```
Дава ни pid-то на **текущия** процес.

```C
#include <sys/types.h>  
#include <unistd.h>  
pid_t getppid(void);
```
Дава ни pid-то на **процесът-родител** на съответния процес. 

**Пример:**
```C
#include  <stdio.h> 
#include  <sys/types.h>  
#include  <unistd.h>  
int main() {
	int pid = fork(); 
	if(pid == -1) {
		perror("Couldn't fork!);
		exit(-1);
	}
	else if(pid > 0) {
		printf("My process ID is %d and my parent is %d\n",getpid(),getppid());
		printf("My child is %d\n", pid);
	}
	else {
		printf("My process ID is %d and my parent is %d",getpid(),getppid());
	}
	printf("something ...");  
	return  0; 
}
```

**Примерен изход:**
```
My process ID is 32157 and my parent is 9981
My child is 32158
something ...
My process ID is 32158 and my parent is 32157
something ...
```

## Завършване на процес - exit()

```C
#include <stdlib.h>
void exit(int return_code);
```
- прекратява процеса, който е извикал примитива незабавно. 

- параметърът return_code указва на процесът-родител с какъв код е завършил процеса.

- системния примитив не връща нищо

- Всички отворени вхдни-изходни потоци, притежание на процеса, се затварят, унищожават се временните файлове, създадени от процеса, процесите-деца на текущия процес стават деца на **init** процеса 

## Системни примитиви wait()  и waitpid()

```C
#include <sys/types.h>
#include <wait.h>
pid_t wait(int * status);
```
- чрез **wait()** процеса-родител изчаква своето дете да приключи.

- примитива връща pid на завършилия процес-дете.

- status параметъра ни дава кода на завършване на процесът-дете.

### Пример
```C
#include <sys/types.h>  
#include <wait.h>
#include <stdio.h> 
#include <sys/types.h>  
#include <unistd.h>  
int main() {
	int status = 0; 
	int pid = fork();
	if(pid == -1) {
		perror("Couldn't fork!");
		exit(-1);
	}
	else if(pid > 0) {
		write(1,"Hello from parent",20);
		printf("I'll wait now ...");
		wait(&status);
		printf("My child has finished with status %d", status);
	}
	else {
		printf("Hello from child");
	}
	return 0;
}
```

**Важно!** Чрез **wait()** процеса-родител изчаква първото дете, което завършва. Чрез **waitpid()** ние можем да кажем на родителя кой специфичен процес-дете да изчака.

```C
#include <sys/types.h>
#include <wait.h>
pid_t waitpid(pid_t pid, int * status, int options);
```

- чрез **pid** указваме кой процес-дете да чака родителя:

	- pid == -1 - чака, което и да е дете да завърши

	- pid > 0 - чака дете с идентификатор pid

	- pid == 0 - чака, което и да е дете от същата група процеси

	- pid < -1 - чака дете от групата с процеси, чиито идентификатор е |pid|

- **status** параметъра ни дава кода на завършване на процесът-дете.

- чрез **options** може да се предотврати блокирането на родителя. При значение WHOHANG процесът-родител не се блокира, ако синът не е завършил и функцията връща 0. 

- функцията връща pid на завършилия процес-дете.


