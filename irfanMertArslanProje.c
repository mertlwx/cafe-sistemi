#include <stdio.h>
#include <string.h>

#define DOGRU_KULLANICI_ADI "admin"
#define DOGRU_SIFRE "1234"

struct Urun {
    char isim[50];
    int fiyat;
    char kategori[10]; 
};


struct Urun urunler[] = {
    {"SoğukLatteKüçük", 10, "Soğuk"}, {"SoğukLatteOrta", 12, "Soğuk"}, {"SoğukLatteBüyük", 14, "Soğuk"},
    {"SoğukMochaKüçük", 11, "Soğuk"}, {"SoğukMochaOrta", 13, "Soğuk"}, {"SoğukMochaBüyük", 15, "Soğuk"},
    {"LimonataKüçük", 9, "Soğuk"}, {"LimonataOrta", 11, "Soğuk"}, {"LimonataBüyük", 13, "Soğuk"},
    {"MilkshakeKüçük", 15, "Soğuk"}, {"MilkshakeOrta", 17, "Soğuk"}, {"MilkshakeBüyük", 19, "Soğuk"},
    {"SıcakÇikolataKüçük", 14, "Sıcak"}, {"SıcakÇikolataOrta", 16, "Sıcak"}, {"SıcakÇikolataBüyük", 18, "Sıcak"},
    {"TürkKahvesiKüçük", 10, "Sıcak"}, {"TürkKahvesiOrta", 12, "Sıcak"}, {"TürkKahvesiBüyük", 14, "Sıcak"},
    {"AmericanoKüçük", 13, "Sıcak"}, {"AmericanoOrta", 15, "Sıcak"}, {"AmericanoBüyük", 17, "Sıcak"},
    {"LatteKüçük", 12, "Sıcak"}, {"LatteOrta", 14, "Sıcak"}, {"LatteBüyük", 16, "Sıcak"},
    {"FiltreKahveKüçük", 11, "Sıcak"}, {"FiltreKahveOrta", 13, "Sıcak"}, {"FiltreKahveBüyük", 15, "Sıcak"}
};


#define URUN_SAYISI (sizeof(urunler) / sizeof(urunler[0]))


int kullaniciGirisi() {
    char kullaniciAdi[20], sifre[20];
    int girisHakki = 3;

    while (girisHakki > 0) {
        printf("\nKullanıcı adınızı giriniz: ");
        scanf("%s", kullaniciAdi);
        printf("Şifrenizi giriniz: ");
        scanf("%s", sifre);

        if (strcmp(kullaniciAdi, DOGRU_KULLANICI_ADI) == 0 && strcmp(sifre, DOGRU_SIFRE) == 0) {
            printf("Giriş başarılı! Sisteme hoş geldiniz.\n\n");
            return 1;
        } else {
            girisHakki--;
            printf("Hatalı giriş. Kalan hakkınız: %d\n", girisHakki);
        }
    }

    printf("Giriş hakkınız doldu. Program sonlandırılıyor.\n");
    return 0;
}


void kategoriListele(char kategori[]) {
    int i, bulundu = 0;

    printf("****** %s İçecekler ******\n", kategori);
    for (i = 0; i < URUN_SAYISI; i++) {
        if (strcmp(urunler[i].kategori, kategori) == 0) {
            printf("%s - %d TL\n", urunler[i].isim, urunler[i].fiyat);
            bulundu = 1;
        }
    }
    if (!bulundu) {
        printf("Bu kategoriye ait içecek bulunmamaktadır.\n");
    }
    printf("--------------------------------\n");
}


void urunFiyatGoster(char secilenUrun[]) {
    int i, bulundu = 0;

    for (i = 0; i < URUN_SAYISI; i++) {
        if (strcmp(secilenUrun, urunler[i].isim) == 0) {
            printf("\n%s: %d TL kasadan ödeme yapınız.\n\n", urunler[i].isim, urunler[i].fiyat);
            bulundu = 1;
            break;
        }
    }
    if (!bulundu) {
        printf("Geçersiz ürün seçimi. Lütfen geçerli bir ürün adı giriniz.\n\n");
    }
}

int main() {
   
    if (!kullaniciGirisi()) {
        return 0; 
    }

    char kategoriSecimi[10];
    char secilenUrun[50];
    int devamEt = 1;

    while (devamEt) {
        printf("Lütfen içecek türünü seçiniz (Sıcak / Soğuk): ");
        scanf("%s", kategoriSecimi);

        
        if (strcmp(kategoriSecimi, "Sıcak") == 0 || strcmp(kategoriSecimi, "Soğuk") == 0) {
            kategoriListele(kategoriSecimi);
        } else {
            printf("Geçersiz kategori. Lütfen 'Sıcak' veya 'Soğuk' yazınız.\n\n");
            continue;
        }

       
        printf("Almak istediğiniz ürünün adını giriniz: ");
        scanf("%s", secilenUrun);

       
        urunFiyatGoster(secilenUrun);

        
        printf("Başka bir sipariş vermek ister misiniz? (1: Evet, 0: Hayır): ");
        scanf("%d", &devamEt);
    }

    printf("Bizi tercih ettiğiniz için teşekkürler. İyi günler dileriz!\n");
    return 0;
}

