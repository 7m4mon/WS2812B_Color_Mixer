# WS2812B_Color_Mixer
Color Mixer w/ WS2812B LEDs Matrix.

  撮影ボックスで小物の撮影をする際、写真が青みがかったり、赤くなったりするときがありますよね。
  照明を任意の色に出来れば解決するんじゃね？ということで、WS2812B LED Matrixを制御する
  任意色の照明コントローラを作ってみました。

  ・RGB各8bitで24bit フルカラー（1677万色）
  ・RGBは独立したボリュームで制御する
  ・Free/LockスイッチをLock側にすることでチラツキを防止
  ・微妙にATmega328とは違うWAVGAT328を使用

  元ネタ(GPLv3)は
  https://create.arduino.cc/projecthub/Arduino_Scuola/color-mixing-addressable-leds-0ca993
  で、あっさり動くかと思いきや、WAVGATのチップはATmega328とは微妙にコンパチではないので
  下記変更を行いました。
  ・ADCの範囲を10bit→12bit（ただし最大4064）に変更
  ・データレートを NEO_KHZ800 → NEO_KHZ400 に変更

  その他、Free/Lockスイッチの処理とレイアウト都合によるmapの変更を行っています。

