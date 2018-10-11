#ifndef INTARRAY_H
#define INTARRAY_H

#include <stdio.h>
#include <string.h>

class IntArray {
public:
   int *array;
   int length;
public:
   IntArray(int size, int val=0):length(size) {
      array = new int[size];
      for(int i=0; i<size; i++)
        array[i] = val;
   }
   
   IntArray(const char* str){
	   length = strlen(str);
	   array = new int[length];
	   for(int i = 0; i<length ; i++){
		   array[i] = str[i];
	   }
   }
   
   int& operator[](int index){
	   return (array[index]);
   }
   
   IntArray operator+(const IntArray &rhs) const {
	   //retArray = new IntArray(length,0);
	   IntArray retArray(length,0);
	   int i = 0;
	   for(i=0;i<length && i<rhs.length ; i++){
		   retArray.array[i] = array[i] + rhs.array[i];
	   }
	   for(; i<length;i++){
		   retArray.array[i] = array[i];
	   }
	   return retArray;
   }
   
   IntArray operator-(const IntArray &rhs) const {
	   IntArray retArray(length,0);
	   int i = 0;
	   for(i=0;i<length && i<rhs.length ; i++){
		   retArray.array[i] = array[i] - rhs.array[i];
	   }
	   for(; i<length;i++){
		   retArray.array[i] = array[i];
	   }
	   return retArray;
   }
   
   IntArray operator*(int x) const {
	   IntArray retArray(length,0);
	   for( int i = 0; i < length ; i++){
		   retArray.array[i] = array[i] * x;
	   }
	   return retArray;
   }
   
   IntArray operator/(int x) const {
	   IntArray retArray(length,0);
	   for( int i = 0; i < length ; i++){
		   retArray.array[i] = array[i] / x;
	   }
	   return retArray;
   }
   
   IntArray operator<<(int count) const {
	   IntArray retArray(length,0);
	   for( int i = 0; i < length ; i++){
		   if((i - count)<0){
			   retArray.array[i] = array[(i+length)-count];
		   }else{
			   retArray.array[i] = array[i-count];
		   }
		   //retArray.array[i] = array[(i-count)%length];
	   }
	   return retArray;
   }

   operator char*() const{
	   char* str;
	   str = new char[length + 1];
	   for(int i=0;i<length;i++){
		   if(array[i] > 255 || array[i]<0){
			   str[i] = ' ';
		   }else{
			   str[i] = array[i];
		   }
	   }
	   str[length] = '\0';
	   return str;
   }
   
   operator int() const {
	   int sum =0;
	   int avg;
	   for(int i=0;i<length;i++){
		   sum+=array[i];
	   }
	   avg=sum/length;
	   
	   return avg;
   }
   
   int getLength(){
	   return length;
   }
   
   void set(int index, int data){
	   array[index] = data;
   }
   
   
   IntArray& operator+=(const IntArray &rhs){
	   for(int i=0;i<length;i++){
		   array[i] = array[i] + rhs.array[i];
	   }
	   return *this;
   }
   
   
  ~IntArray() { delete [] array; }

   int get(int index) {
       return array[index];
   }
};

#endif //INTARRAY_H
