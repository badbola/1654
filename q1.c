#include<semaphore.h>
#include<stdio.h>

semaphore customers = 0;
semaphore customers1 =0;
semaphore barbers = 0;
semaphore cutting = 0;
semaphore mutex = 1;
int customer1,n=2 = 0;
void barber() {
while(true) {
wait(customers);
wait(mutex); //
customers1 = customers1 - 1;
signal(barbers);
signal(mutex);
cut_hair();
}
}
void customer() {
wait(mutex);
if (customers1 < n) {
customers1 = customers1 + 1;
signal(customers);
signal(mutex);
wait(barbers);
get_haircut();
}
else {
signal(mutex);
}
}
void cut_hair(){
waiting(cutting);
}
get_haircut(){
printf("get hair cut for some time");
signal(cutting);
}
int main(){
barber();
customer();
cut_hair();
}
