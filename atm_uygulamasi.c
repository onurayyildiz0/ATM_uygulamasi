#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int bakiye;

int menu(){
	
	system("cls");
	int secim;
	
	printf("\nKullanilabilir Bakiye : %d TL \n\n",bakiye);
	
	printf("\tBankamatik uygulamasi \n");
	printf("\t1-- para cek \n");
	printf("\t2-- para yatir \n");
	printf("\t3-- fatura ode \n");
	printf("\t4-- havale/EFT \n");
	printf("\t5-- cikis \n");
	scanf("%d",&secim);
	return secim;
	
}

void paraCek(){
	
	
	int miktar;
	printf("miktar (TL) :");
	scanf("%d",&miktar);
	printf("isleminiz gerceklestiriliyor...\n");
	sleep(2);
	if(miktar > bakiye){
		printf("yetersiz bakiye...\n");
	}
	else{
		
		bakiye -= miktar;
		printf("islem basariyla gerceklestirildi\n");
		sleep(2);
		printf("paranizi almayi unutmayiniz.\n");
		sleep(2);
	}
	
	printf("Ana menuye yonlendirliyorsunuz... \n");
	sleep(2);

}

void paraYatir(){
	
	int miktar;
	printf("yatiricaginiz paranin miktarini girip parayi yerlestiriniz: ");
	scanf("%d",&miktar);
	printf("isleminiz gerceklestiriliyor... \n");
	sleep(2);
	
	if(miktar < 0)
	printf("lutfen islemini size ayrilan sure icinde gerceklestiriniz... !\n");
	else
	{
		bakiye += miktar;
		printf("islem basariyla gerceklestirildi\n");
		sleep(2);
	}
	printf("Ana menuye yonlendiriliyorsunuz...\n");
	sleep(2);	
}

void faturaOde(){
	
	int faturaBedeli = rand()%100 + 20 , numara;
	int secim;
	printf("1- elektrik \n");
	printf("2- su \n");
	printf("3- dogalgaz \n");
	printf("4- telefon \n");
	scanf("%d",&secim);
	if(secim < 1 || secim > 4)
	printf("hatali islem yaptiniz... !\n");
	else
	{
		
		printf("fatura no : ");
		scanf("%d",&numara);
		printf("isleminiz gerceklestiriliyor... \n");
		sleep(2);
		printf("O... A....... adina kayitli fatura bedeli : %d TL\n",faturaBedeli);
		printf("1 - islemi onayliyorum ?");
		scanf("%d",&secim);
		if(secim != 1)
		printf("islem iptal edildi... \n");
		else if(faturaBedeli <= bakiye)
		{
			printf("isleminiz gerceklestirliyor... \n");
			sleep(2);
			bakiye -= faturaBedeli;
			printf("isleminiz basariyla gerceklestirildi...\n");
			sleep(2);
				
		}
		else
		printf("yetersiz bakiye! \n");
	}
	
	printf("Ana menuye yonlendiriliyorsunuz... \n");
	sleep(2);	
}

void havaleEFT()
{
	
	int miktar,iban;
	printf("havale/EFT yapcaginiz kisinin IBAN numrasi : ");
	scanf("%d",&iban);
	printf("havale miktari (TL): ");
	scanf("%d",&miktar);
	printf("isleminiz gerceklestiriliyor...\n");
	sleep(2);
	if(miktar > bakiye)
	printf("yetersiz bakiye !\n");
	else
	{
		bakiye -= miktar;
		printf("havale/EFT islemi basariyla gerceklestirildi... \n");
		sleep(2);
	}
	printf("Ana menuye yonlediriliyorsunuz...\n");
	sleep(2);
	
}



int main(){
	
	int parola;
	int i = 0;
	print("kart sifrenizi giriniz:\n");
	scanf("%d",&parola);
	
	while(parola != 1234)
	{
		printf("hatali sifre !\nkart sifresi: ");
		scanf("%d",&parola);
		
		if(i == 3){
			
			printf("kartiniz kilitlenmistir !\nLutfen musteri hizmetleri ile iletisime geciniz...");
			
		}
		i++;
	}
	printf("giris basarili...\n");
	sleep(1);
	srand(time(NULL));
	bakiye = rand() % 900 + 100;
	int secim;
	while(1){
		
		secim = menu();
		switch(secim)
		{
			case 1:paraCek();
			break;
			case 2:paraYatir();
			break;
			case 3:faturaOde();
			break;
			case 4: havaleEFT();
			break;
			case 5:printf("kartinizi almayi unutmayiniz...");
			default : printf("hatali islem !!!\n");
			break;
		}
	}
	
}
