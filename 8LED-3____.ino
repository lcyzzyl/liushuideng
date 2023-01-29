/*
 http://shop34791330.taobao.com/ //德飞莱旗舰店
 http://qixingchong.tmall.com/   //七星虫旗舰店
 http://www.doflye.net //德飞莱技术论坛
 http://www.doflye.net/forum-98-1.html //德飞莱论坛arduino版块

 1个共阳数码管，显示0-9数字
 
 使用独立模块开发板LY-51S连接详情：
 http://www.doflye.net/thread-5298-1-1.html
 
 */

// 简易的led流水效果3,LED灯随机亮灭。8个LED灯共阳连接，GPIO口输出低电平点亮LED灯，输出高电平，熄灭LED灯。 

int ledCount=8;
//定义段码，这里是共阴段码，如果是共阳只需要在程序中把读到的值按位取反即可
//const unsigned char dofly_DuanMa[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

const unsigned char dofly_DuanMa[4]={0x55,0xaa,0x55,0xaa};

int ledPins[] = { 
  2, 3, 4, 5, 6, 7,8,9, };   // 对应的led引脚


void setup() {
// 循环设置，把对应的led都设置成输出
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
}
// 数据处理，把需要处理的byte数据写到对应的引脚端口。
void deal(unsigned char value){
  
 for(int i=0;i<8;i++)
   {
   long val = random(0,7); //随机函数，val的值在0-7之间随机产生
   digitalWrite(ledPins[i],!bitRead(value,val));//使用了bitRead函数，非常简单
//bitRead(4,3)这里的第一个参数，其实就是我们给定的那个数，我们用来读取的那个目标；
//第二个参数是我们要读取的这个目标数转化为二进制后的指定位置，比如十进制的4转化为二进制后为00000100，我们指定读取右边第三位，则n为3；
//从低位开始读
// !bitRead(value,i)，这里前面加！(非运算符号)，取决于使用的是共阴还是共阳数码管。

//当i=0时，ledPins[0]是2，2脚的状态通过bitRead（value，0）函数，读出value的第一位，循环8次，就按我们的要求点亮了8个二极管
 //  delay(100);
   }
}
// 主循环
void loop() {
  // 循环显示
  for(int i=0;i<2;i++){
     deal(dofly_DuanMa[i]);//读取对应的段码值
     delay(100);          //调节延时，2个数字之间的停留间隔
  }
  }
