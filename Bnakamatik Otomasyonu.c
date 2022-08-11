
// Bnakamatik Kasa Otomasyonu

// kütüphane deklarasyonu
#include <stdio.h> // printf ve scanf fonksiyonlarını kullanabilmek için gerekli

// fonksiyon prototipleri 
void ParaKasasi(int,int,int); // bütün işlemi yapan fonksiyon (main içinde işlem yapılmayacak)
void KasayiGoster(int,int,int,int,int,int); // 1 . seçeneği karşılayan fonksiyon
int BakiyeHesapla(int,int,int,int,int);  // banknot durumuna göre kasadaki para miktarını hesaplar

// para yatırma işlemi için gerekli fonksiyonlar
// parametre olarak girilen tutarı alır ve ilgili banknota yönelik işlemi yapar
int YuzTlMiktari(int); // girilen para miktarı içindeki 100 tl adedini hesaplar
int ElliTlMiktari(int);// girilen para miktarı içindeki 50 tl adedini hesaplar
int YirmiTlMiktari(int);// girilen para miktarı içindeki 20 tl adedini hesaplar
int OnTlMiktari(int);// girilen para miktarı içindeki 10 tl adedini hesaplar
int BesTlMiktari(int);// girilen para miktarı içindeki 5 tl adedini hesaplar

// main() fonksiyonu, sadece bir fonksiyonu çağırır ve parametre olarak sadece seçim ve tutar değişkenlerini verir.
int main()
{
	int secenek,tutar,tutar2; // tutar2 herhangi bir banknot sıfırlanınca girilen para miktarını diğer banknotlardan 
	printf("-------------------------------------------- \n");
	ParaKasasi(tutar,secenek,tutar2);  // kaksanın fonksiyonlarını yapar // içerisinde birçok fonksiyon çağırır
	return 0;
}
// bütün işlemler bu fonksiyon içinde gerçekleşecek
// main fonksiyonu içinde herhangi bir işlem yapılmayacak
// proje pdf inde belirtildiği gibi çokça fonksiyon ve alt program içerir
void ParaKasasi(int secenek,int tutar,int tutar2) 
{
	int kontrol=1,bakiye,yeniBkiye,kalan,yuz=10,elli=20,yirmi=50,on=50,bes=50; // istenilen sayıdaki banknotlar
	int yuzTlIlkDurum,elliTlIlkDurum,yirmiTlIlkDurum,onTlIlkDurum,besTlIlkDurum; // banknotların işlem görmeden önceki halleri
     // bannotlardan herhangibi 0 olursa
	// diğer az miktardaki banknottan karşılanacak mikarı temsil ederler
	
	while(kontrol) // kontrol değişkeni, her işlem bitiminde menüye dönmek için kullanılır eğer 4. seeçenek seçilirse
	{                                                                      // değeri 0 olur ve while döngüsü biter,program sonlanır
		bakiye=BakiyeHesapla(bes, on, yirmi, elli, yuz); // bakiyeyi hesaplar
		// menü bölümü
		printf("\t MENU \n");
		printf(" 1. Kasayi Goster \n");
		printf(" 2. Para Cekme \n");
		printf(" 3. Para Yatirma \n");
		printf(" 4. Cikis \n");
		printf(" Seciminiz : ");scanf("%d",&secenek); // kullanıcının yapacağı işlemi seçeceği  kısım
		printf("---------------------------- \n");
		switch(secenek)
		{
			case 1: // kasayı gösterme işlemi
				KasayiGoster(bakiye,bes,on,yirmi,elli,yuz);
				break;
			case 2: // para çekme işlemini yapar
				printf("---- Para Cekme------------- \n");
				printf("---------------------------- \n");
				printf(" Cekilecek Miktar :");scanf("%d",&tutar);
				
				if (tutar>bakiye) // girilen para miktarı kasadaki para miktarından büyükse mesaj ver
				{
					printf(" Kasada Yeterli Miktarda Para Mevcut Degil ! \n");
					printf("---------------------------- \n");
				}
				else if (tutar%5 !=0) // girilen para miktarı ilgili banknotlar türünden değilse kabul edilmez
				{
					printf(" 5 tl ve katlarindaki banknotlar giriniz !\n");
					printf("---------------------------- \n");
				}
				else // her iki şartı sağlıyorsa para çekme işlemi başlar
				{		
					printf(" Mevcut Bakiye : %d TL \n",bakiye);
					bakiye = bakiye - tutar; // bakiyeden girilen tutarı çıkar
					// girilen tutar içindeki 100 lük banknot miktarı kasadakinden az ise 
					if(yuz>tutar/100)				
					{												
						yuz-=tutar/100;tutar=tutar%100; // 100 lük banknotlardan çıkart, tutarın yüz ile kalanını diğer banknota gönder
					}
					else //değilse
					{
						tutar-=yuz*100; yuz=0;	 // girilen tutardan 100 lük banknot miktarını çıkar, yuzlük banknot sayısını 0 la					
					}					
					if(elli>tutar/50)				
					{
						elli-=tutar/50;tutar=tutar%50;	// 50 lik banknotlardan çıkart, tutarın elli ile kalanını diğer banknota gönder			
					}
					else
					{				
						tutar-=elli*50;elli=0;	// girilen tutardan 50 lik banknot miktarını çıkar, ellilik  banknot sayısını 0 la					
					}
					
					if(yirmi>tutar/20)
					{
						yirmi-=tutar/20;tutar=tutar%20; // 20 lik banknotlardan çıkart, tutarın 20 ile kalanını diğer banknota gönder	
					}
					
					else
					{
						tutar-=yirmi*20;yirmi=0; // girilen tutardan 20 lik banknot miktarını çıkar, yirmilik  banknot sayısını 0 la			
					}
					
					if(on>tutar/10)
					{					
						on-=tutar/10;tutar=tutar%10; // 10 luk banknotlardan çıkart, tutarın 10 ile kalanını diğer banknota gönder
					}
					
					else
					{
						tutar-=on*10;on=0; // girilen tutardan 10 luk banknot miktarını çıkar, onluk  banknot sayısını 0 la		
					}
					
					if(bes>tutar/5)
					{
						bes-=tutar/5;tutar=tutar%5;  // 5lik banknotlardan çıkart, tutarın 5 ile kalanını diğer banknota gönder
					}
					
					else
					{					
						tutar-=bes*5;bes=0;// girilen tutardan 5 lik banknot miktarını çıkar, beslik  banknot sayısını 0 la
					}
					
					printf(" Yeni Bakiye : %d \n",bakiye);
					if (bakiye<=0) // eğer girilen tutar kasayı sıfırlar ise mesaj ver 
					{
						bakiye=0;
						printf(" Kasa Bos ! Para Ekleyiniz !\n");
					}
					printf("---------------------------- \n");
				}
				break;
			case 3: // para yatırma işlemini yapar
				printf("---- Para Yatirma ---------- \n");
				printf("---------------------------- \n");
				printf(" Yatirilacak Miktar : ");scanf("%d",&tutar);
				printf(" Mevcut Bakiye : %d TL\n",bakiye);
				if (tutar%5 !=0) // girilen tutar 5 ve katları şeklinde değilse hata mesajı ver
				{
					printf(" Yalnizca 5 tl ve katlarindaki banknotlar kabul edilir ! \n");
				}
				else // değilse yatırma işlemine devam et
				{
					yuz +=YuzTlMiktari(tutar); //  para yatıma işleminde girilen tutar fonksiyonlara parametre gönderilmiştir
					elli +=ElliTlMiktari(tutar); // fonksiyonlarda gerekli işlemler yapılarak ilgili banknota atanmıştır
					yirmi +=YirmiTlMiktari(tutar);
					on +=OnTlMiktari(tutar);
					bes +=BesTlMiktari(tutar);
					bakiye =BakiyeHesapla(bes, on, yirmi, elli, yuz);
					printf(" Yeni Bakiye : %d \n",bakiye);
					printf("---------------------------- \n");					
				}
				break;
			case 4: // çıkış işlemi 
				printf("---- Cikis ----- \n");
				printf(" Cikis Yapiliyor ! \n");
				kontrol=0; // kontrol değişkeninin değeri 0 yapılarak döngü sonlandırılmıştır
				break;
		}	
	}
}

// kasayı gösterme fonksiyonu;
void KasayiGoster(int bakiye,int bes,int on,int yirmi,int elli,int yuz)
{
	bakiye=BakiyeHesapla(bes, on, yirmi, elli, yuz); // bakiyeyi hesaplar 
	printf("------- Kasayi Goster ------ \n");
	printf("---------------------------- \n");
	printf(" Mevcut Bakiye %d TL \n",bakiye);
	printf(" Kasanin Durumu : \n");
	printf(" 5 TL Banknot Miktari : %d \n",bes);
	printf(" 10 TL Banknot Miktari : %d \n",on);
	printf(" 20 TL Banknot Miktari : %d \n",yirmi);
	printf(" 50 TL Banknot Miktari : %d \n",elli);
	printf(" 100 TL Banknot Miktari : %d \n",yuz);
	printf("---------------------------- \n");
}

// bakiye değerini hesaplar, kasayı göster fonksiyonunda değerini gösterir
int BakiyeHesapla(int bes, int on,int yirmi, int elli, int yuz)
{
	int bakiye1=bes*5 + on*10 + yirmi*20 + elli*50 + yuz*100;
	return bakiye1;
}
int YuzTlMiktari(int tutar) // girilen para miktarını ve ilgili banknotu parametre alır
{
	int yuz=(tutar-tutar%100)/100; // girilen para miktarının içinde kaç tane 100 tl olduğunu bulur
	return yuz; // bulduğu değeri geri döndürür.
}
int ElliTlMiktari(int tutar) 
{
	int elli=(tutar%100-tutar%50)/50; // girilen para miktarının içinde kaç tane 50 tl olduğunu bulur
	return elli; 
}
int YirmiTlMiktari(int tutar)
{ 
	int yirmi=(tutar%50-(tutar%50)%20)/20;  // girilen para miktarının içinde kaç tane 20 tl olduğunu bulur
	return yirmi;
}
int OnTlMiktari(int tutar)
{
	int on=(((tutar%50)%20)-tutar%10)/10;   // girilen para miktarının içinde kaç tane 10 tl olduğunu bulur
	return on;
}
int BesTlMiktari(int tutar)   // girilen para miktarının içinde kaç tane 5 tl olduğunu bulur
{
	int bes=(tutar%10)/5;
	return bes;
}
///////////////////////////////////////////-------------------------------------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


