
// Bnakamatik Kasa Otomasyonu

// k�t�phane deklarasyonu
#include <stdio.h> // printf ve scanf fonksiyonlar�n� kullanabilmek i�in gerekli

// fonksiyon prototipleri 
void ParaKasasi(int,int,int); // b�t�n i�lemi yapan fonksiyon (main i�inde i�lem yap�lmayacak)
void KasayiGoster(int,int,int,int,int,int); // 1 . se�ene�i kar��layan fonksiyon
int BakiyeHesapla(int,int,int,int,int);  // banknot durumuna g�re kasadaki para miktar�n� hesaplar

// para yat�rma i�lemi i�in gerekli fonksiyonlar
// parametre olarak girilen tutar� al�r ve ilgili banknota y�nelik i�lemi yapar
int YuzTlMiktari(int); // girilen para miktar� i�indeki 100 tl adedini hesaplar
int ElliTlMiktari(int);// girilen para miktar� i�indeki 50 tl adedini hesaplar
int YirmiTlMiktari(int);// girilen para miktar� i�indeki 20 tl adedini hesaplar
int OnTlMiktari(int);// girilen para miktar� i�indeki 10 tl adedini hesaplar
int BesTlMiktari(int);// girilen para miktar� i�indeki 5 tl adedini hesaplar

// main() fonksiyonu, sadece bir fonksiyonu �a��r�r ve parametre olarak sadece se�im ve tutar de�i�kenlerini verir.
int main()
{
	int secenek,tutar,tutar2; // tutar2 herhangi bir banknot s�f�rlan�nca girilen para miktar�n� di�er banknotlardan 
	printf("-------------------------------------------- \n");
	ParaKasasi(tutar,secenek,tutar2);  // kaksan�n fonksiyonlar�n� yapar // i�erisinde bir�ok fonksiyon �a��r�r
	return 0;
}
// b�t�n i�lemler bu fonksiyon i�inde ger�ekle�ecek
// main fonksiyonu i�inde herhangi bir i�lem yap�lmayacak
// proje pdf inde belirtildi�i gibi �ok�a fonksiyon ve alt program i�erir
void ParaKasasi(int secenek,int tutar,int tutar2) 
{
	int kontrol=1,bakiye,yeniBkiye,kalan,yuz=10,elli=20,yirmi=50,on=50,bes=50; // istenilen say�daki banknotlar
	int yuzTlIlkDurum,elliTlIlkDurum,yirmiTlIlkDurum,onTlIlkDurum,besTlIlkDurum; // banknotlar�n i�lem g�rmeden �nceki halleri
     // bannotlardan herhangibi 0 olursa
	// di�er az miktardaki banknottan kar��lanacak mikar� temsil ederler
	
	while(kontrol) // kontrol de�i�keni, her i�lem bitiminde men�ye d�nmek i�in kullan�l�r e�er 4. see�enek se�ilirse
	{                                                                      // de�eri 0 olur ve while d�ng�s� biter,program sonlan�r
		bakiye=BakiyeHesapla(bes, on, yirmi, elli, yuz); // bakiyeyi hesaplar
		// men� b�l�m�
		printf("\t MENU \n");
		printf(" 1. Kasayi Goster \n");
		printf(" 2. Para Cekme \n");
		printf(" 3. Para Yatirma \n");
		printf(" 4. Cikis \n");
		printf(" Seciminiz : ");scanf("%d",&secenek); // kullan�c�n�n yapaca�� i�lemi se�ece�i  k�s�m
		printf("---------------------------- \n");
		switch(secenek)
		{
			case 1: // kasay� g�sterme i�lemi
				KasayiGoster(bakiye,bes,on,yirmi,elli,yuz);
				break;
			case 2: // para �ekme i�lemini yapar
				printf("---- Para Cekme------------- \n");
				printf("---------------------------- \n");
				printf(" Cekilecek Miktar :");scanf("%d",&tutar);
				
				if (tutar>bakiye) // girilen para miktar� kasadaki para miktar�ndan b�y�kse mesaj ver
				{
					printf(" Kasada Yeterli Miktarda Para Mevcut Degil ! \n");
					printf("---------------------------- \n");
				}
				else if (tutar%5 !=0) // girilen para miktar� ilgili banknotlar t�r�nden de�ilse kabul edilmez
				{
					printf(" 5 tl ve katlarindaki banknotlar giriniz !\n");
					printf("---------------------------- \n");
				}
				else // her iki �art� sa�l�yorsa para �ekme i�lemi ba�lar
				{		
					printf(" Mevcut Bakiye : %d TL \n",bakiye);
					bakiye = bakiye - tutar; // bakiyeden girilen tutar� ��kar
					// girilen tutar i�indeki 100 l�k banknot miktar� kasadakinden az ise 
					if(yuz>tutar/100)				
					{												
						yuz-=tutar/100;tutar=tutar%100; // 100 l�k banknotlardan ��kart, tutar�n y�z ile kalan�n� di�er banknota g�nder
					}
					else //de�ilse
					{
						tutar-=yuz*100; yuz=0;	 // girilen tutardan 100 l�k banknot miktar�n� ��kar, yuzl�k banknot say�s�n� 0 la					
					}					
					if(elli>tutar/50)				
					{
						elli-=tutar/50;tutar=tutar%50;	// 50 lik banknotlardan ��kart, tutar�n elli ile kalan�n� di�er banknota g�nder			
					}
					else
					{				
						tutar-=elli*50;elli=0;	// girilen tutardan 50 lik banknot miktar�n� ��kar, ellilik  banknot say�s�n� 0 la					
					}
					
					if(yirmi>tutar/20)
					{
						yirmi-=tutar/20;tutar=tutar%20; // 20 lik banknotlardan ��kart, tutar�n 20 ile kalan�n� di�er banknota g�nder	
					}
					
					else
					{
						tutar-=yirmi*20;yirmi=0; // girilen tutardan 20 lik banknot miktar�n� ��kar, yirmilik  banknot say�s�n� 0 la			
					}
					
					if(on>tutar/10)
					{					
						on-=tutar/10;tutar=tutar%10; // 10 luk banknotlardan ��kart, tutar�n 10 ile kalan�n� di�er banknota g�nder
					}
					
					else
					{
						tutar-=on*10;on=0; // girilen tutardan 10 luk banknot miktar�n� ��kar, onluk  banknot say�s�n� 0 la		
					}
					
					if(bes>tutar/5)
					{
						bes-=tutar/5;tutar=tutar%5;  // 5lik banknotlardan ��kart, tutar�n 5 ile kalan�n� di�er banknota g�nder
					}
					
					else
					{					
						tutar-=bes*5;bes=0;// girilen tutardan 5 lik banknot miktar�n� ��kar, beslik  banknot say�s�n� 0 la
					}
					
					printf(" Yeni Bakiye : %d \n",bakiye);
					if (bakiye<=0) // e�er girilen tutar kasay� s�f�rlar ise mesaj ver 
					{
						bakiye=0;
						printf(" Kasa Bos ! Para Ekleyiniz !\n");
					}
					printf("---------------------------- \n");
				}
				break;
			case 3: // para yat�rma i�lemini yapar
				printf("---- Para Yatirma ---------- \n");
				printf("---------------------------- \n");
				printf(" Yatirilacak Miktar : ");scanf("%d",&tutar);
				printf(" Mevcut Bakiye : %d TL\n",bakiye);
				if (tutar%5 !=0) // girilen tutar 5 ve katlar� �eklinde de�ilse hata mesaj� ver
				{
					printf(" Yalnizca 5 tl ve katlarindaki banknotlar kabul edilir ! \n");
				}
				else // de�ilse yat�rma i�lemine devam et
				{
					yuz +=YuzTlMiktari(tutar); //  para yat�ma i�leminde girilen tutar fonksiyonlara parametre g�nderilmi�tir
					elli +=ElliTlMiktari(tutar); // fonksiyonlarda gerekli i�lemler yap�larak ilgili banknota atanm��t�r
					yirmi +=YirmiTlMiktari(tutar);
					on +=OnTlMiktari(tutar);
					bes +=BesTlMiktari(tutar);
					bakiye =BakiyeHesapla(bes, on, yirmi, elli, yuz);
					printf(" Yeni Bakiye : %d \n",bakiye);
					printf("---------------------------- \n");					
				}
				break;
			case 4: // ��k�� i�lemi 
				printf("---- Cikis ----- \n");
				printf(" Cikis Yapiliyor ! \n");
				kontrol=0; // kontrol de�i�keninin de�eri 0 yap�larak d�ng� sonland�r�lm��t�r
				break;
		}	
	}
}

// kasay� g�sterme fonksiyonu;
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

// bakiye de�erini hesaplar, kasay� g�ster fonksiyonunda de�erini g�sterir
int BakiyeHesapla(int bes, int on,int yirmi, int elli, int yuz)
{
	int bakiye1=bes*5 + on*10 + yirmi*20 + elli*50 + yuz*100;
	return bakiye1;
}
int YuzTlMiktari(int tutar) // girilen para miktar�n� ve ilgili banknotu parametre al�r
{
	int yuz=(tutar-tutar%100)/100; // girilen para miktar�n�n i�inde ka� tane 100 tl oldu�unu bulur
	return yuz; // buldu�u de�eri geri d�nd�r�r.
}
int ElliTlMiktari(int tutar) 
{
	int elli=(tutar%100-tutar%50)/50; // girilen para miktar�n�n i�inde ka� tane 50 tl oldu�unu bulur
	return elli; 
}
int YirmiTlMiktari(int tutar)
{ 
	int yirmi=(tutar%50-(tutar%50)%20)/20;  // girilen para miktar�n�n i�inde ka� tane 20 tl oldu�unu bulur
	return yirmi;
}
int OnTlMiktari(int tutar)
{
	int on=(((tutar%50)%20)-tutar%10)/10;   // girilen para miktar�n�n i�inde ka� tane 10 tl oldu�unu bulur
	return on;
}
int BesTlMiktari(int tutar)   // girilen para miktar�n�n i�inde ka� tane 5 tl oldu�unu bulur
{
	int bes=(tutar%10)/5;
	return bes;
}
///////////////////////////////////////////-------------------------------------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


