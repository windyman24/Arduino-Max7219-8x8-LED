#include <SPI.h>
#include "number.h"
//定義 
#define No_Op  0x00
#define Digit0 0x01
#define Digit1 0x02
#define Digit2 0x03
#define Digit3 0x04
#define Digit4 0x05
#define Digit5 0x06
#define Digit6 0x07
#define Digit7 0x08

#define DecodeMode  0x09
#define Intensity   0x0A
#define ScanLimit   0x0B
#define Shutdown    0x0C
#define DisplayTest 0x0F

#define CS_pin      10

void MAX7219_write(byte address, byte data)
{
  digitalWrite(CS_pin, LOW);
  SPI.transfer(address);
  SPI.transfer(data);
  digitalWrite(CS_pin, HIGH);
}
void setup() {
  SPISettings(1000000, MSBFIRST, SPI_MODE0);
  SPI.begin();
  pinMode(CS_pin, OUTPUT);
  //解碼模式設定
  MAX7219_write(DecodeMode, 0x00);
  //亮度設定
  MAX7219_write(Intensity, 0x02);
  //顯示開啟ON
  MAX7219_write(Shutdown, 0x01);
  //關閉顯示測試
  MAX7219_write(DisplayTest, 0x00);
  //掃描顆數
  MAX7219_write(ScanLimit, 0x07);
}
byte booltoByte(int (*ShowArray_ptr)[8])
{
  byte data = 0x00;

  for (int i = 0; i < 8; i++)
    data = data << 1 | ShowArray_ptr[0][i];

  return data;
}
void draw(int (*ShowArray_ptr)[8])
{
  MAX7219_write(Digit0, booltoByte(&ShowArray_ptr[0]));
  MAX7219_write(Digit1, booltoByte(&ShowArray_ptr[1]));
  MAX7219_write(Digit2, booltoByte(&ShowArray_ptr[2]));
  MAX7219_write(Digit3, booltoByte(&ShowArray_ptr[3]));
  MAX7219_write(Digit4, booltoByte(&ShowArray_ptr[4]));
  MAX7219_write(Digit5, booltoByte(&ShowArray_ptr[5]));
  MAX7219_write(Digit6, booltoByte(&ShowArray_ptr[6]));
  MAX7219_write(Digit7, booltoByte(&ShowArray_ptr[7]));
}
void clear()
{
  MAX7219_write(Digit0, 0x00);
  MAX7219_write(Digit1, 0x00);
  MAX7219_write(Digit2, 0x00);
  MAX7219_write(Digit3, 0x00);
  MAX7219_write(Digit4, 0x00);
  MAX7219_write(Digit5, 0x00);
  MAX7219_write(Digit6, 0x00);
  MAX7219_write(Digit7, 0x00);
}

void loop() {
  clear();//清除畫面
  delay(500);
  draw(&show_num0[0]);//顯示數字1
  delay(1000);
  draw(&show_num1[0]);//顯示數字1
  delay(1000);
  draw(&show_num2[0]);//顯示數字1
  delay(1000);
  draw(&show_num3[0]);//顯示數字1
  delay(1000);
  draw(&show_num4[0]);//顯示數字1
  delay(1000);
  draw(&show_num5[0]);//顯示數字1
  delay(1000);
  draw(&show_num6[0]);//顯示數字1
  delay(1000);
  draw(&show_num7[0]);//顯示數字1
  delay(1000);
  draw(&show_num8[0]);//顯示數字1
  delay(1000);
  draw(&show_num9[0]);//顯示數字1
  delay(1000);
}
