# libBC

**libBC**, C dili ile yazılmış, temel algoritmalar, veri yapıları işlemleri ve yardımcı makrolar içeren hafif bir kütüphanedir. Bu kütüphane, düşük seviyeli bit işlemlerinden dizi sıralama, arama algoritmalarına kadar geniş bir yelpazede işlevsellik sunar.

## Özellikler

- **Matematiksel Makrolar:**
  - `SQUARE(x)`: Bir sayının karesini hesaplar.
  - `IS_ODD(x)` ve `IS_EVEN(x)`: Sayının tek ya da çift olup olmadığını kontrol eder.
  - `POWER_OF_TWO(x)`: Bir sayının 2'nin kuvveti olup olmadığını belirler.
  - `FAKTORIYEL(x)`: Önceden tanımlı `factor` dizisini kullanarak faktöriyel hesaplaması yapar.

- **Tarih ve Zaman Yardımcıları:**
  - `DAY(x)` ve `MONTH(x)`: Gün ve ay isimlerini döndürür.

- **Bit Manipülasyonu:**
  - `SET_BIT`, `CLEAR_BIT`, `TOGGLE_BIT`, `CHECK_BIT`: Bit seviyesinde işlem yapmanıza olanak sağlar.
  - `LOW_BYTE(x)`, `HIGH_BYTE(x)`, `MAKE_WORD(high, low)`: Byte düzeyinde işlemler için makrolar.

- **Genel Amaçlı Yardımcı Makrolar:**
  - `asize(x)`: Bir dizinin eleman sayısını hesaplar.
  - `ABS(x)`, `MAX(a,b)`, `MIN(a,b)`: Temel matematiksel işlemler.
  - `ZERO_ARRAY(arr)` ve `FILL_ARRAY(arr,val)`: Bellek doldurma işlemlerini kolaylaştırır.
  - `START_TIMER()` ve `END_TIMER()`: Kod parçalarının çalışma süresini ölçer.

- **Dizi İşlemleri:**
  - `bclib_bubble_sort`: Basit bubble sort algoritması.
  - `bclib_sort_array`: Kullanıcı tanımlı karşılaştırma fonksiyonu kullanarak genel dizi sıralama.
  - `bclib_binary_search`: Binary search algoritması.
  - `bclib_find_value`, `bclib_get_min`, `bclib_get_max`: Dizi içerisindeki belirli değerleri veya sınırları bulur.
  - `bclib_print_array`: Dizi elemanlarını ekrana yazdırır.

- **Bellek İşlevleri:**
  - `bclib_memset`, `bclib_memcpy`, `bclib_memchr`: Bellek yönetim fonksiyonları.
  - `bclib_generic_swap`: Genel amaçlı bellek değişim fonksiyonu.
  - `bclib_reverse`: Bellekteki veriyi tersine çevirir.

- **String İşlemleri:**
  - `bclib_strlen`: String uzunluğunu hesaplar.
  - `bclib_strcpy`, `bclib_strcat`: String kopyalama ve birleştirme işlemleri.
  - `bclib_strcmp`: String karşılaştırma.
  - `bclib_strrchr`: Bir karakterin string içerisindeki son geçtiği yeri bulur.
  - `bclib_string_print`: String dizilerini ekrana yazdırır.

- **Rastgele Sayı ve Sıralama Callback’leri:**
  - `bclib_random`: Rastgele sayı üretimi.
  - `bclib_qsort_int_cb`, `bclib_qsort_double_cb`, `bclib_qsort_float_cb`, `bclib_qsort_string_cb`: Farklı veri tipleri için karşılaştırma callback fonksiyonları.

- **Diğer Yardımcı İşlevler:**
  - `is_empty`: Bir dizinin boş olup olmadığını kontrol eder.
  - `sumIntArray`: Bir tamsayı dizisindeki elemanların toplamını hesaplar.

- **Hata Kaydı (Logging):**
  - `LOG_ERROR`: LOG makrosu aktif olduğunda hata mesajlarını dosya ve satır bilgisi ile loglar.

## Kurulum

1. **Kaynak Kodun İndirilmesi:**
   ```bash
   git clone https://github.com/uzunberkay/libBC.git
   cd libBC
