# battleship
This is the simple c language version of fleet battle game 

* Oyun 2 oyuncu ile oynanmaktadır.
* Her oyuncunun bir txt dosyası oluşturup gemilerinin konumlarını yazması gerekmektedir. Aşağıda verilen örnekten yaralanılabilir.
        (+ işareti geminin bulunduğunu ifade ediyor.)

       A     B     C     D     E     F
1      +     -     -     -     -     -
2      -     -     +     -     +     +
3      -     -     +     -     -     -
4      -     -     +     -     -     -
5      -     -     -     -     -     +
6      -     -     -     +     -     +

* Oynanacak alan 6x6' lık olmalıdır.
* 2 tane bir birimlik gemi (örnek: 1A ve 6D),
  2 tane iki birimlik gemi (örnek: 2E 2F ve 5F 6F),
  1 tane üç birimlik gemi (örnek: 2C 3D 4D) ile oynanır.

* İki ve üç birimlik gemiler yatay veya dikey olarak yerleştirilebilir (diagonal olarak yerleştirilemez). 

* Yukarıdaki örnek baz alınırsa txt dosyasının içine bir birimlik gemilerden başlanarak üç birimliğe kadar:
        
        1A 6D 2E 2F 5F 6F 2C 3D 4D
  
  aralarında 1 boşluk bırakılarak yazılır.

* Program rastgele olarak hangi oyuncunun başlayacağına karar verdikten sonra oyun başlar.
* Oyuncular sırayla karşı tarafın hangi konumunu bombalamak istiyorlarsa ekrana yazarlar.
        (Örneğin oyuncu1 oyuncu2'nin 6A konumunda gemi olduğunu düşünüyorsa ekrana 6A yazmalıdır.)

* Oyun başladığında her iki oyuncunun tablosu da bombalanmadı anlamına gelen "-" işaretleri ile gösterilir. 
* Oyuncular gemileri vurmayı başarırlarsa "X" işareti konur.
* Oyuncular ıskalarsa "*" işareti konur.

* Karşı tarafın tüm gemilerini bombalayan oyuncu kazanır.