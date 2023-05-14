#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;   //KUYRUKTAKÝ ELEMANIN VERÝSÝNÝ TUTAR.
	struct node * next;  //KUYRUKTAKÝ ELEMANIN GÖSTERÝCÝSÝNÝ TUTAR.
};
  //KUYRUK YAPISI
struct node *temp=NULL;    //ELEMANI TUTACAK GEÇÝÇÝ BÝR DEÐÝÞKEN OLUÞTURULUR.
struct node *head=NULL;    //KUYRUÐUN BAÞINDAKÝ ELEMANI TUTAR.
struct node *tail=NULL;    //KUYRUÐUN SONUNDAKÝ ELEMANI TUTAR.



void ElemanEkle(int sayi)
{
	struct node *eleman=(struct node*)malloc(sizeof(struct node));
	eleman->data=sayi;
	
	if(head==NULL){        //EÐER BAÞTAKÝ ELEMAN NULL ÝSE YANÝ KUYRUKTA ELEMAN YOKSA:
		head=eleman;  
		head->next=head;
		tail=eleman;
		tail->next=NULL;
	}
	
	else if(head->next==head){      //EÐER KUYRUKTA TEK ELEMAN VARSA:
	    tail->next=eleman;
	    tail=eleman;
	    tail->next=NULL;
	    head->next=tail;
		
	}
	
	else{           //EÐER KUYRUKTA BÝRDEN FAZLA ELEMAN VARSA:
		tail->next=eleman;
		tail=eleman;
		tail->next=NULL;
	}
	
}

void ElemanSil()
{
	if(head==NULL)       //EÐER BAÞTAKÝ ELEMAN NULL ÝSE YANÝ KUYRUKTA ELEMAN YOKSA:
		printf("KUYRUK BOS...");
		
	else{    //EÐER KUYRUKTA BÝR VE BÝRDEN FAZLA ELEMAN VARSA:
	    printf("%d elmani kuyruktan cikartildi ",head->data);
		temp=head->next;
	    free(head);
	    head=temp;	
	}
	
}

void yazdir()      //EKRANA YAZDIRMA FONKSÝYONU 
{
	system("cls");    //HER YAZDIRMADAN ÖNCE EKRANI TEMÝZLER.
	if(head==NULL)
	   printf("KUYRUK BOS...");
	   
	else{
		temp=head;
		while(temp->next!=NULL){    //SON ELEMANA GELENE KADAR YAZDIRIR.
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);  //SON ELEMANI YAZDIRIR.
	}

   printf("\n");
}


int main() {
	int secim,sayi;
	while(1){   //ÇIKANA KADAR SEÇÝMLER EKRANA YAZDIRILIR
		printf("\nLutfen asagidaki islemlerden birini seciniz \n");
		printf("1.Ekleme\n");
		printf("2.SIlme\n");
		printf("3.Goruntuleme\n");
		printf("4.CIKIS\n");
		printf("SECIMINIZ:");
		scanf("%d",&secim);    //YAPACAÐI ÝÞLEM KULLANICIDAN ALINIR
		
		switch(secim){
			case 1:    // 1 GÝRÝLÝRSE EKLEME ÝÞLEMÝ YAPILIR
			printf("Eklenicek sayiyi giriniz:");
			scanf("%d",&sayi);  //EKLENÝLCEK SAYI KULLANICIDAN ALINIR
			ElemanEkle(sayi);   //EKLEME FONKSÝYONUNA ELEMAN GÖNDERÝLÝR
			break;
			
			case 2:   // 2 GÝRÝLÝRSE SÝLME ÝÞLEMÝ YAPILIR
			ElemanSil();  //SÝLME FONKSÝOYONU ÇAÐIRILIR
			break;
			
			case 3:  // 3 GÝRÝLÝRSE ELEMANLAR EKRANA YAZDIRILIR
			yazdir();   //YAZDIRMA FONKSÝYONU ÇAÐIRILIR
			break;
			
			case 4:  // 4 GÝRÝLÝRSE ÇIKIÞ YAPILIR
				return 0;  
			
			default:  // 1,2,3,4 DIÞINDA BÝR KARAKTER GÝRÝLÝRSE HATA VERÝR 
			printf("ISTENEN SECIMLERDEN BIRINI GIRMEDINIZ!!\n");
		
		}
	}
}
