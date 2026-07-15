# 🎮 Arduino LCD Keypad Pac-Man Mini Oyunu

Bu proje, C tabanlı Arduino programlama dili kullanılarak donanım üzerinde çalışacak şekilde geliştirilmiş, fiziksel etkileşimli bir mini oyun prototipidir. Standart bir LCD Keypad Shield üzerindeki fiziksel butonlarla kontrol edilen bu projede, temel oyun döngüsü (game loop) ve bellek yönetimi prensipleri donanıma başarılı bir şekilde entegre edilmiştir.

## 🛠️ Kullanılan Donanım ve Teknolojiler
* Arduino UNO (veya uyumlu mikrodenetleyici)
* 16x2 LCD Keypad Shield
* C (Arduino IDE) & `LiquidCrystal.h` Kütüphanesi

## 💡 Öne Çıkan Teknik Geliştirmeler
* **Asenkron Çalışma:** Programın kilitlenmesini önlemek ve akıcı bir oyun deneyimi sunmak için, mikrodenetleyiciyi durduran `delay()` fonksiyonu yerine, arka planda çalışan `millis()` zamanlayıcısı kullanılmıştır.
* **Bellek Optimizasyonu:** Oyun alanı 16 karakterlik tek boyutlu bir dizi (Array) olarak haritalandırılmış, böylece mikrodenetleyicinin kısıtlı hafızası (SRAM) maksimum verimle kullanılmıştır.
* **Analog Sinyal İşleme:** Yönlendirme mekanizması, tek bir analog pinden (A0) okunan voltaj eşik değerlerine göre (ADC) yorumlanarak dijital eylemlere dönüştürülmüştür.
* **Özel Karakter (Custom Character) Üretimi:** Byte matrisleri ile Pac-Man ağız açma/kapama animasyonları kurgulanmış ve donanım ekranına özel olarak çizdirilmiştir.

## 🚀 Nasıl Çalıştırılır?
1. Kodları Arduino IDE üzerinden açın.
2. Gerekli donanım bağlantılarını yapıp doğru COM portunu seçin.
3. Kodu karta yükleyin (Upload).
4. Shield üzerindeki Yön (Sağ, Sol) tuşlarını kullanarak ekrandaki tüm yıldızları toplayıp 15 puana ulaşmaya çalışın!
