# --- task 1 ---

tee f1
touch f2
cp f1 f3
mkdir dir1
cd dir1
mv ../f1 ff1
mv ../f2 ff2
mv ../f3 ff3

# --- task 2 ---

mkdir del
mv f* del
rm -ir del #this asks for every file in del. -Ir asks only once

# --- task 3 ---

grep "Georgi" /etc/passwd  #this searches for the pattern Georgi, it will find also "Georgiev" 
#grep -w /etc/passwd "Georgi" - this maches whole word

# --- task 4 ---
grep -v "s8" /etc/passwd 

# --- task 5 ---
find / -name dir* -type d 2>/dev/null

# --- task 6 ---
find ~ -name *.txt -exec wc -c {} \; 2>/dev/null

#OR

cd 
find . -name *.txt -exec wc -c {} \; 2>/dev/null

# --- task 7 ---

find / -group student -exec tail -n 5 {} \; 2>/dev/null

# --- task 8 ---

file ~/* 

#OR

cd 
file *

# --- task 9 ---

cut -d ":" -f 5 /etc/passwd

# --- task 10 ---

sort /etc/passwd -o passwd_sorted
cmp /etc/passwd passwd_sorted

