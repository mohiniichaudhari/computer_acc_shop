#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
//Used macro
#define FILE_NAME "productRecordSystem.bin"
#define FILE_NAME1 "customerRecordSystem.bin"
// Macro related to the product info
#define MAX_USERNAME 20
#define MAX_PASSWORD 20
#define MAX_PRODUCT_NAME 30
#define MAX_PHNO 12
#define MAX_CUSTOMER_NAME 30
#define MAX_CUSTOMER_EMAIL 50
#define MAX_CUSTOMER_ADDRESS 150

char loged_user[MAX_USERNAME];

//function declaration
void mainPage(void);
void welcomePage(void);
void mainMenu(void);
void loginScreen(void);
void adminMenu(void);
void adminManageProduct(void);
void adminManageCustomer(void);
void addProductInDataBase(void);
void viewProduct(void);
void searchProductByName(void);
void updateProduct(void);
void deleteProduct(void);
void addCustomerInDataBase(void);
void viewCustomer(void);
void searchCustomerByName(void);
void updateCustomer(void);
void customerMenu(void);
void customerRegistration(void);
void customerLogin(void);
void customerMainMenu(void);
void manageProfile(void);
void myDetails(void);
void editMyProfile(void);
void changeMyPassword(void);
void purchaseProduct(void);


//Structure to store product data
//Elements of structure
typedef struct// to call in program
{
    unsigned int product_id; // declare the integer data type
    char productName[MAX_PRODUCT_NAME];// declare the charecter data type
    int qty; // declare the integer data type
    int price; // declare the integer data type
   
} s_ProductInfo;

//structure to store customer data
typedef struct// to call in program
{
	unsigned int customer_id;
	char username[MAX_USERNAME];
	char password[MAX_PASSWORD];
	char customerName[MAX_CUSTOMER_NAME];
	char customerAddress[MAX_CUSTOMER_ADDRESS];
	char ph_no[MAX_PHNO];
}s_CustomerInfo;
char* getCurrentDate() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char *buffer = malloc(20 * sizeof(char));
    strftime(buffer, 20, "%Y-%m-%d", tm_info);
    return buffer;
}
//---------------------------------------------------------------------
//Main function
int main()
{
    mainPage();
    welcomePage();
    return 0;
}
//---------------------------------------------------------------------

//Display page title in center
void pageTitleCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (120 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}

//fucntion for validation
int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}

//Page title
void subTitle(const char* message){
	printf("\n\t\t\t\t\t========================================================================================\n");
	pageTitleCenter(message);
	printf("\n\t\t\t\t\t========================================================================================\n");
	
}

//Head message
void mainTitle(const char* message)
{
    system("cls");
    printf("\n\t\t\t=============== **************************************************************************************** ===============");
    printf("\n\t\t\t||           || *************                                                              ************* ||           ||");
    printf("\n\t\t\t||           || *************                     COMPUTER ACCESSORIES SHOP                ************* ||           ||");
    printf("\n\t\t\t=============== *************                      MANAGEMENT SYSTEM IN C                  ************* ===============");
	printf("\n\t\t\t      ||        *************                                                              *************        ||      ");
    printf("\n\t\t\t   ========     ****************************************************************************************     ========   ");
    subTitle(message);
}


//Project Main page 
void mainPage(){
	mainTitle("SCET MCA");
	printf("\n\n\t\t\t\t\t****************************************************************************************");
	printf("\n\t\t\t\t\t|                                                                                      |");
	printf("\n\t\t\t\t\t|   SUBMITTED TO:                                 SUBMITTED BY:                        |");
	printf("\n\t\t\t\t\t|   ~~~~~~~~~~~~~~                                ~~~~~~~~~~~~~~                       |");
	printf("\n\t\t\t\t\t|   Ms. Preksha Parmar                     Beladiya Rudrali Prvinbhai                  |");
	printf("\n\t\t\t\t\t|                                          Lakhani Priyanshi Shaileshbhai              |");
	printf("\n\t\t\t\t\t|                                          Chaudhari Mohini Gambhirbhai                |");
//	printf("\n\t\t\t\t|                                                                                      |");
	printf("\n\t\t\t\t\t****************************************************************************************");
	printf("\n\n\n\t\t\t\t\t\t\t\t Enter any key to continue.....");
    getch();

}

//Project Welcome page
void welcomePage(){
	mainTitle("POOJA SHOP");
	printf("\n\n\n");
    printf("\n\t\t\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\t\t\t\t\t\t\t        ---------------------------------------------");
    printf("\n\t\t\t\t\t\t\t        |                   WELCOME                 |");
    printf("\n\t\t\t\t\t\t\t        |                     TO                    |");
    printf("\n\t\t\t\t\t\t\t        |         COMPUTER ACCRSSORIES SHOP         |");
    printf("\n\t\t\t\t\t\t\t        |                 MANAGEMENT                |");
    printf("\n\t\t\t\t\t\t\t        |                   SYSTEM                  |");
    printf("\n\t\t\t\t\t\t\t        ---------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t Enter any key to continue.....");
    getch();
    mainMenu();
}

//Project Main menu
void mainMenu(){
	system("cls");
	int choice=0;
	do{
		mainTitle("MAIN MENU");
		printf("\n\n\n\t\t\t\t\t\t\t\t\t1.Admin");
		printf("\n\t\t\t\t\t\t\t\t\t2.Customer");
		printf("\n\t\t\t\t\t\t\t\t\t0.Exit");
		printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter choice => ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				loginScreen();
				break;
			case 2:
				customerMenu();
				break;
			case 0:
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tThank you!!!\n\n\n\n\n");
	            exit(1);
				break;
			default:
				printf("Exit");
		}
	}while(choice!=0);
}

//---------------------------------------------------------------------
//-------------------------------Admin side----------------------------
//Admin login
void loginScreen(){
	system("cls");
	mainTitle("LOGIN SCREEN");
	int e=0;
	char username[15];
	char password[15];
	char original_username[20]="pooja";
	char original_password[10]="12345";
	 do {
        printf("\n\n\n\n\t\t\t\t\t\t\t\tEnter your Username and Password:)");
        printf("\n\n\n\t\t\t\t\t\t\t\t\tUSERNAME:");
        scanf("%s", username);
        printf("\n\n\t\t\t\t\t\t\t\t\tPASSWORD:");

        // Display '*' characters for password input
        int i = 0;
        while (1) {
            char ch = getch();
            if (ch == '\r' || ch == '\n') {
                break;
            } else if (ch == 8 && i > 0) { // Backspace
                printf("\b \b");
                i--;
            } else {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0'; // Null-terminate the password

        if (strcmp(username, original_username) == 0 && strcmp(password, original_password) == 0) {
            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t.......Login Successful.......");
            getch();
            adminMenu();
            break;
        } else {
            printf("\n\n\n\t\t\t\t\t\t\t\t\tUsername or Password is incorrect. Please try again:)");
            e++;
            getch();
        }
    } while (e <= 2);

    system("cls");
    getch();
}
//Admin main menu
void adminMenu(){
	system("cls");
	int choice;
	do{
		mainTitle("ADMIN MENU");
		printf("\n\n\n\t\t\t\t\t\t\t\t\t1. Manage Products\n");
		printf("\n\t\t\t\t\t\t\t\t\t2. Manage Customers\n");
		printf("\n\t\t\t\t\t\t\t\t\t0. Exit\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tChoose from 1 and 2 :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				adminManageProduct();
				break;
			case 2:
				adminManageCustomer();
				break;
			case 0:
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tThank you!!!\n\n\n\n\n");
				getch();
				break;
			default:
				printf("\n\t\t\t\t\t\t\t\t\t\tInvalid entry. Please enter right option:)");
				getch();	
		}
	}while(choice!=0);
}

//Admin manage product menu
void adminManageProduct(){
	system("cls");
	int choice;
		do{
		mainTitle("MANAGE PRODUCTS MENU");
		printf("\n\n\n\t\t\t\t\t\t\t\t\t1. Add Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t2. List Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t3. Search Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t4. Edit Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t5. Delete Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t0. Exit\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tChoose from 1 to 5:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				addProductInDataBase();
				break;
			case 2:
				viewProduct();
				break;
			case 3:
				searchProductByName();
				break;
			case 4:
				updateProduct();
				break;
			case 5:
				deleteProduct();
				break;
			case 0:
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\tThank you!!!\n\n\n\n\n");
				getch();
				break;
			default:
				printf("\n\t\t\t\t\t\t\t\t\t\tInvalid entry. Please enter right option:)");
				getch();
		}
	}while(choice!=0);
}

//Add product in list
// Function to validate product ID
int isProductIdValid(unsigned int productId)
{
    return (productId > 0); // Product ID should be a positive value
}

// Function to validate product name
int isProductNameValid(const char *productName)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(productName);
    for (index = 0; index < len; ++index)
    {
        if (!(isalpha(productName[index])) && (productName[index] != '\n') && (productName[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
// Function to validate product quantity
int isQuantityValid(int qty)
{
    return (qty > 0); // Quantity should be a positive value
}
// Function to validate product price
int isPriceValid(int price)
{
    return (price > 0); // Price should be a positive value
}

//Add product in list
void addProductInDataBase(){
	s_ProductInfo addProductInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    char ans;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
	mainTitle("ADD NEW PRODUCT");
    printf("\n\n\t\t\t\t\t\t\t\t\tENTER DETAILS BELOW:");
    printf("\n\t\t\t\t\t\t\t\t\t====================\n");
     do
    {
        printf("\n\t\t\t\t\t\t\t\t\tProduct ID  = ");
        fflush(stdin);
        scanf("%u", &addProductInfoInDataBase.product_id);
        status = isProductIdValid(addProductInfoInDataBase.product_id);
        if (!status)
        {
            printf("\n\t\t\t\t\t\t\t\t\tInvalid product ID. Please enter a positive value.");
        }
    } while (!status);
    do
    {
        printf("\n\t\t\t\t\t\t\t\t\tProduct Name  = ");
        fflush(stdin);
        fgets(addProductInfoInDataBase.productName,MAX_PRODUCT_NAME,stdin);
        status = isProductNameValid(addProductInfoInDataBase.productName);
        if (!status)
        {
            printf("\n\t\t\t\t\t\t\t\t\tProduct Name contain invalid character. Please enter again.");
        }
	}while(!status);
	  do
    {
        printf("\n\t\t\t\t\t\t\t\t\tProduct QTY  = ");
        fflush(stdin);
        scanf("%d", &addProductInfoInDataBase.qty);
        status = isQuantityValid(addProductInfoInDataBase.qty);
        if (!status)
        {
            printf("\n\t\t\t\t\t\t\t\t\tInvalid quantity. Please enter a positive value.");
        }
    } while (!status);
	   do
    {
        printf("\n\t\t\t\t\t\t\t\t\tProduct Price  = ");
        fflush(stdin);
        scanf("%d", &addProductInfoInDataBase.price);
        status = isPriceValid(addProductInfoInDataBase.price);
        if (!status)
        {
            printf("\n\t\t\t\t\t\t\t\t\tInvalid price. Please enter a positive value.");
        }
    } while (!status);
	
	//Write data in to file
	fwrite(&addProductInfoInDataBase,sizeof(addProductInfoInDataBase), 1, fp);
	fclose(fp);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t....Information record Successfully....");
	fclose(fp);
	sd:
	getch();
	printf("\n\n\t\t\t\t\t\t\t\t\t\tDo you want to add more[Y/N]?? ");
	scanf(" %c",&ans);
	if(toupper(ans)=='Y'){
		addProductInDataBase();
	}else if(toupper(ans)=='N'){
		printf("\n\t\t\t\t\t\t\t\t\t\t\tThank you :) :) ");
		getch();
	}else{
		printf("\n\t\t\t\t\t\t\t\t\tInvalid Input");
		goto sd;
	}
}

//Display list of the product
void viewProduct(){
	int found = 0;
	s_ProductInfo addProductInfoInDataBase = {0};
	FILE *fp = NULL;
	unsigned int countProduct = 1;
	mainTitle("VIEW PRODUCT DETAILS");
	fp = fopen(FILE_NAME,"rb");
	if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
//    printf("\n%6s | %10s | %4s | %6s\n", "ID", "Product Name", "Qty", "Price");
//    printf("-----------------------------------------------------------\n");
    while (fread (&addProductInfoInDataBase, sizeof(addProductInfoInDataBase), 1, fp))
    {
//    	printf("\n%-6d | %-10s | %-4d | %-6d", addProductInfoInDataBase.product_id, addProductInfoInDataBase.productName, addProductInfoInDataBase.qty, addProductInfoInDataBase.price);
        printf("\n\t\t\t\t\t\t\t\t\tProduct Count = %d\n\n",countProduct);
        printf("\t\t\t\t\t\t\t\t\tProduct id = %u\n",addProductInfoInDataBase.product_id);
        printf("\t\t\t\t\t\t\t\t\tProduct Name = %s",addProductInfoInDataBase.productName);
        printf("\t\t\t\t\t\t\t\t\tProduct QTY = %d\n",addProductInfoInDataBase.qty);
        printf("\t\t\t\t\t\t\t\t\tProduct Price = %d\n",addProductInfoInDataBase.price);
       printf("\t\t\t\t\t\t\t\t\t==========================\n");
        found = 1;
        ++countProduct;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\t\t\t\t\t\t\tNo Record");
    }
    printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getch();
}

//Search product by product name
void searchProductByName(){
	int found = 0;
	char product_name[MAX_PRODUCT_NAME];
	unsigned int countProduct = 1;
	s_ProductInfo addProductInfoInDataBase = {0};
	FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
    mainTitle("SEARCH PRODUCT");
    printf("\n\n\t\t\t\t\t\t\t\t\tEnter PRODUCT NAME to search: ");
	fflush(stdin);
	fgets(product_name,MAX_PRODUCT_NAME,stdin);
    while (fread (&addProductInfoInDataBase, sizeof(addProductInfoInDataBase), 1, fp)){
    	if(strcmp(addProductInfoInDataBase.productName,product_name)==0){
    		found = 1;
    		break;
		}
	}
	if(found){
		printf("\n\t\t\t\t\t\t\t\t\tProduct id = %u\n",addProductInfoInDataBase.product_id);
        printf("\t\t\t\t\t\t\t\t\tProduct Name = %s",addProductInfoInDataBase.productName);
        printf("\t\t\t\t\t\t\t\t\tProduct QTY = %d\n",addProductInfoInDataBase.qty);
        printf("\t\t\t\t\t\t\t\t\tProduct Price = %d\n",addProductInfoInDataBase.price);
	}else{
		printf("\n\t\t\t\t\t\t\t\t\tNo Record");
	}
	fclose(fp);
    printf("\n\n\n\t\t\t\t\t\t\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getch();
}

//Update product details by admin
void updateProduct() {
    int found = 0;
    int productId = 0;
    long pos = 0;
    s_ProductInfo addProductInfoInDataBase = {0};
    FILE *fp = NULL;
    
    mainTitle("UPDATE PRODUCT");
    
    fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
    
    printf("\n\t\t\t\t\t\t\t\tEnter PRODUCT ID to update: ");
    fflush(stdin);
    scanf("%u",&productId);
    
    while (fread(&addProductInfoInDataBase, sizeof(addProductInfoInDataBase), 1, fp)) {
    	if(addProductInfoInDataBase.product_id == productId){
    		
            found = 1;
            pos = ftell(fp) - sizeof(addProductInfoInDataBase);
            
            printf("\n\t\t\t\t\t\t\t\tEnter new details for the product\n");
            printf("\n\t\t\t\t\t\t\t\t\t\tProduct ID: ");
            scanf("%u", &addProductInfoInDataBase.product_id);
            
            printf("\n\t\t\t\t\t\t\t\t\t\tProduct Name: ");
            fflush(stdin);
            fgets(addProductInfoInDataBase.productName, MAX_PRODUCT_NAME, stdin);
            
            printf("\n\t\t\t\t\t\t\t\t\t\tProduct Quantity: ");
            scanf("%d", &addProductInfoInDataBase.qty);
            
            printf("\n\t\t\t\t\t\t\t\t\t\tProduct Price: ");
            scanf("%d", &addProductInfoInDataBase.price);
            
            // Move the file pointer to the position where the data needs to be updated
            fseek(fp,pos,SEEK_SET);
            
            // Write the updated product data to the file
            fwrite(&addProductInfoInDataBase, sizeof(addProductInfoInDataBase), 1, fp);
            break;
        }
    }
    
    if (found) {
        printf("\n\t\t\t\t\t\t\t\t\t\tProduct updated successfully.\n");
    } else {
        printf("\n\t\t\t\t\t\t\t\t\t\tProduct not found.\n");
    }
    
    fclose(fp);
    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to go back to the admin menu.....");
    fflush(stdin);
    getch();
}

//delete product by admin
void deleteProduct(){
	int found = 0;
	int productDelete = 0;
	s_ProductInfo addProductInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    mainTitle("DELETE PRODUCT");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
	tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
    printf("\n\t\t\t\t\t\t\t\t\tEnter Product ID NO. for delete:");
    scanf("%d",&productDelete);
    while (fread (&addProductInfoInDataBase, sizeof(addProductInfoInDataBase), 1, fp))
    {
        if(addProductInfoInDataBase.product_id != productDelete)
        {
            fwrite(&addProductInfoInDataBase,sizeof(addProductInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\t\t\t\t\t\t\tRecord deleted successfully....."):printf("\n\t\t\t\t\t\t\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
	printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to go back to the admin menu.....");
    getch();
}

//Admin manage customers menu
void adminManageCustomer(){
	system("cls");
	int choice;
		do{
		mainTitle("MANAGE CUSTOMER MENU");
//		printf("\n\n\n\t\t\t\t\t\t\t\t\t1. Add Customer\n");
		printf("\n\t\t\t\t\t\t\t\t\t1. List All Customer\n");
		printf("\n\t\t\t\t\t\t\t\t\t2. Search Customer\n");
		printf("\n\t\t\t\t\t\t\t\t\t3. Edit Customer\n");
//		printf("\n\t\t\t\t\t\t\t\t\t\t5. Delete Customer\n");
		printf("\n\t\t\t\t\t\t\t\t\t0. Exit\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tChoose from 1 to 3:");
		scanf("%d", &choice);
		switch(choice){
//			case 1:
////				addCustomerInDataBase();
//				break;
			case 1:
				viewCustomer();
				break;
			case 2:
				searchCustomerByName();
				break;
			case 3:
				updateCustomer();
				break;
			case 0:
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\tThank you!!!\n\n\n\n\n");
				getch();
				break;
			default:
				printf("\n\t\t\t\t\t\t\t\t\tInvalid entry. Please enter right option:)");
				getch();
		}
	}while(choice!=0);
}
//int isCustomerIdValid(unsigned int custId)
//{
//    return (custId > 0); // Product ID should be a positive value
//}

//add customer in list
//void addCustomerInDataBase(){
//	s_CustomerInfo addCustomerInfoInDataBase = {0};
//    FILE *fp = NULL;
//    int status = 0;
//    char ans;
//    fp = fopen(FILE_NAME1,"ab+");
//    if(fp == NULL)
//    {
//        printf("\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
//        exit(1);
//    }
//	mainTitle("ADD NEW CUSTOMER");
//    printf("\n\n\t\t\t\t\t\t\t\t\tENTER DETAILS BELOW:");
//    printf("\n\t\t\t\t\t\t\t\t\t====================\n");
//   // In your addCustomerInDataBase() function:
//	
//	do
//    {
//        printf("\n\t\t\t\t\t\t\t\t\tCustomer ID  = ");
//        fflush(stdin);
//        scanf("%u", &addCustomerInfoInDataBase.customer_id);
//        status = isCustomerIdValid(addCustomerInfoInDataBase.customer_id);
//        if (!status)
//        {
//            printf("\n\t\t\t\t\t\t\t\t\tInvalid Customer ID. Please enter a positive value.");
//        }
//    } while (!status);
//
//    do
//    {
//        printf("\n\t\t\t\t\t\t\t\t\tCustomer Name  = ");
//        fflush(stdin);
//        fgets(addCustomerInfoInDataBase.customerName,MAX_CUSTOMER_NAME,stdin);
//        status = isNameValid(addCustomerInfoInDataBase.customerName);
//        if (!status)
//        {
//            printf("\n\t\t\t\t\t\t\t\t\t\tCustomer Name contain invalid character. Please enter again.");
//        }
//	}while(!status);
//	
//	printf("\n\t\t\t\t\t\t\t\t\tCustomer Phone Number = ");
//	fflush(stdin);
//    scanf("%d",&addCustomerInfoInDataBase.ph_no);
//	
//	printf("\n\t\t\t\t\t\t\t\t\tCustomer Address  = ");
//    fflush(stdin);
//    fgets(addCustomerInfoInDataBase.customerAddress,MAX_CUSTOMER_ADDRESS,stdin);
//	
//	
//	//Write data in to file
//	fwrite(&addCustomerInfoInDataBase,sizeof(addCustomerInfoInDataBase), 1, fp);
//	fclose(fp);
//	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t....Information record Successfully....");
//	fclose(fp);
//	sd:
//	getch();
//	printf("\n\n\t\t\t\t\t\t\t\tDo you want to add more[Y/N]?? ");
//	scanf(" %c",&ans);
//	if(toupper(ans)=='Y'){
//		addCustomerInDataBase();
//	}else if(toupper(ans)=='N'){
//		printf("\n\t\t\t\t\t\t\t\t\t\t\t Thank you :) :) ");
//		getch();
//	}else{
//		printf("\n\t\t\t\t\t\t\t\t\t\tInvalid Input");
//		goto sd;
//	}
//}

//Display list of the Customer
void viewCustomer()
{
    int found = 0;
    s_CustomerInfo addCustomerInfoInDataBase = {0};
    FILE *fp = NULL;
    unsigned int countCustomer = 1;
    mainTitle("VIEW CUSTOMER DETAILS");
    fp = fopen(FILE_NAME1,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }

    while (fread (&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp))
    {
    	
        printf("\n\t\t\t\t\t\t\t\t\tCustomer Count = %d\n\n",countCustomer);
        
//        printf("\n %80s %25s %20s %20s","Customer_ID","Customer_NAME","Customer_PhoneNumber","Cust_Address");
		printf("\n\t\t\t\t\t\t\t\t\tCustomer id = %u\n",addCustomerInfoInDataBase.customer_id);	
		printf("\t\t\t\t\t\t\t\t\tUserName = %s",addCustomerInfoInDataBase.username);	
//		printf("\t\t\t\t\t\t\t\t\tPassword = %s\n",addCustomerInfoInDataBase.password);	
        int i;
		int passwordLength = strlen(addCustomerInfoInDataBase.password);
        printf("\t\t\t\t\t\t\t\t\tPassword = ");
        for (i = 0; i < passwordLength; ++i)
        {
            printf("*");
        }
        printf("\n");
		printf("\t\t\t\t\t\t\t\t\tCustomer Name = %s",addCustomerInfoInDataBase.customerName);
        printf("\t\t\t\t\t\t\t\t\tPhone Number = %s\n",addCustomerInfoInDataBase.ph_no);
        printf("\t\t\t\t\t\t\t\t\tCustomer Address = %s\n",addCustomerInfoInDataBase.customerAddress);
        printf("\t\t\t\t\t\t\t\t\t==========================\n");
       
        found = 1;
        ++countCustomer;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\tNo Record");
    }
    printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getch();
}

//Search customer by customer name
void searchCustomerByName(){
	int found = 0;
	char customer_name[MAX_CUSTOMER_NAME];
	unsigned int countCustomer = 1;
	s_CustomerInfo addCustomerInfoInDataBase = {0};
	FILE *fp = NULL;
    fp = fopen(FILE_NAME1,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
    mainTitle("SEARCH CUSTOMER");
    printf("\n\n\t\t\t\t\t\t\t\t\tEnter CUSTOMER NAME to search: ");
	fflush(stdin);
	fgets(customer_name,MAX_CUSTOMER_NAME,stdin);
    while (fread (&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp)){
    	if(strcmp(addCustomerInfoInDataBase.customerName,customer_name)==0){
    		found = 1;
    		break;
		}
	}
	if(found){
		printf("\n\t\t\t\t\t\t\t\t\tCustomer id = %u\n",addCustomerInfoInDataBase.customer_id);
        printf("\t\t\t\t\t\t\t\t\tUserName = %s",addCustomerInfoInDataBase.username);
		printf("\t\t\t\t\t\t\t\t\tCustomer Name = %s",addCustomerInfoInDataBase.customerName);
        printf("\t\t\t\t\t\t\t\t\tCustomer Phone Number  = %d\n",addCustomerInfoInDataBase.ph_no);
        printf("\t\t\t\t\t\t\t\t\tCustomer Address = %s\n",addCustomerInfoInDataBase.customerAddress);
	}else{
		printf("\n\t\t\t\t\t\t\t\t\t\tNo Record");
	}
	fclose(fp);
    printf("\n\n\n\t\t\t\t\t\t\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getch();
}

//Update cutomer details by admin
void updateCustomer() {
    int found = 0;
    int status=0;
    int customerId = 0;
    long pos = 0;
    s_CustomerInfo addCustomerInfoInDataBase = {0};
    FILE *fp = NULL;
    
    mainTitle("UPDATE CUSTOMER");
    
    fp = fopen(FILE_NAME1, "rb+");
    if (fp == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
    
    printf("\n\t\t\t\t\t\t\t\t\tEnter CUSTOMER ID to update: ");
    fflush(stdin);
    scanf("%u",&customerId);
    
    while (fread(&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp)) {
    	if(addCustomerInfoInDataBase.customer_id == customerId){
            
			found = 1;
            pos = ftell(fp) - sizeof(addCustomerInfoInDataBase);
            
            printf("\n\t\t\t\t\t\t\t\t\tEnter new details for the Customer:\n");
            printf("\n\t\t\t\t\t\t\t\t\t\tCustomer ID: ");
            scanf("%u", &addCustomerInfoInDataBase.customer_id);
            
            
            printf("\n\t\t\t\t\t\t\t\t\t\tCustomer Name: ");
            fflush(stdin);
            fgets(addCustomerInfoInDataBase.customerName, MAX_CUSTOMER_NAME, stdin);
            
              do{
	        	printf("\n\t\t\t\t\t\t\t\t\t\tYour Phone Number = ");
			    fflush(stdin);
			    fgets(addCustomerInfoInDataBase.ph_no,MAX_PHNO,stdin);
			    status=isValidPhone(addCustomerInfoInDataBase.ph_no);
			    if(!status){
			        printf("\n\t\t\t\t\t\t\t\t\tPhone number contain only 10 digits. Please enter again.");
			    }	
        	}while(!status);
            printf("\n\t\t\t\t\t\t\t\t\t\tCustomer Address: ");
            scanf("%d", &addCustomerInfoInDataBase.customerAddress);
            
            // Move the file pointer to the position where the data needs to be updated
            fseek(fp, pos, SEEK_SET);
            
            // Write the updated product data to the file
            fwrite(&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp);
            break;
        }
    }
    
    if (found) {
        printf("\n\t\t\t\t\t\t\t\t\t\tCustomer updated successfully.\n");
    } else {
        printf("\n\t\t\t\t\t\t\t\t\t\tCustomer not found.\n");
    }
    
    fclose(fp);
    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to go back to the admin menu.....");
    fflush(stdin);
    getch();
}


//----------------------------Customer side----------------------------
//Customer Menu
void customerMenu(){
	system("cls");
	int choice;
	do{
		mainTitle("CUSTOMER MENU");
		printf("\n\n\n\t\t\t\t\t\t\t\t\t1. Registration\n");
		printf("\n\t\t\t\t\t\t\t\t\t2. Login\n");
		printf("\n\t\t\t\t\t\t\t\t\t3. List Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t4. Search Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t0. Exit\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tChoose from 1 and 4 :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				customerRegistration();
				break;
			case 2:
				customerLogin();
				break;
			case 3:
				viewProduct();
				break;	
			case 4:
				searchProductByName();
				break;	
			case 0:
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tThank you!!!\n\n\n\n\n");
				loged_user[0]='\0';
				getch();
				break;
			default:
				printf("\t\t\t\t\t\t\t\t\t\tInvalid entry. Please enter right option:)");
				getch();	
		}
	}while(choice!=0);
}
int isPasswordValid(const char *password) {
    int length = 0;
    int i;
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;

    // Check the length of the password
    while (password[length] != '\0') {
        length++;
    }

    if (length < 8) {
        return 0; // Password is too short
    }

    // Check for at least one uppercase letter, one lowercase letter, one digit, and one special character
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpperCase = 1;
        } else if (islower(password[i])) {
            hasLowerCase = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (!isalnum(password[i])) {
            hasSpecialChar = 1;
        }
    }

    // Check if all criteria are met
    if (hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) {
        return 1; // Valid password
    } else {
        return 0; // Invalid password
    }
}

//validation phone
int isValidPhone(const char *phno)
{
	int validPhno=1;
	int len=0;
	int index=0;
	len=strlen(phno);
	if(len==11){
		for(index=0;index<len-1;++index){
			if(!isdigit(phno[index])){
				validPhno=0;
				break;
			}
		}
	}else{
		validPhno=0;
	}
	return validPhno;
}
//Customer Registration
void customerRegistration(){
	s_CustomerInfo addCustomerInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    char ans;
    fp = fopen(FILE_NAME1,"ab+");
    if(fp == NULL)
    {
        printf("\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
	mainTitle("CUSTOMER REGISTATION");
    printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t\t\t\t\t\t\t====================\n");
    printf("\n\t\t\t\t\t\t\t\t\tCustomer ID  = ");
    fflush(stdin);
    scanf("%u",&addCustomerInfoInDataBase.customer_id);
    
    printf("\n\t\t\t\t\t\t\t\t\tUsername  = ");
    fflush(stdin);
    fgets(addCustomerInfoInDataBase.username,MAX_USERNAME,stdin);

do {
        printf("\n\t\t\t\t\t\t\t\t\tPassword  = ");
        fflush(stdin);
        int i = 0;
        while (i < MAX_PASSWORD - 1) {
            addCustomerInfoInDataBase.password[i] = getch();
            if (addCustomerInfoInDataBase.password[i] == '\r') {
                break;
            } else {
                printf("*");
                i++;
            }
        }
        addCustomerInfoInDataBase.password[i] = '\0';  // Null-terminate the password

        // Validate the password
        status = isPasswordValid(addCustomerInfoInDataBase.password);

        if (!status) {
            printf("\n\t\t\t\t\t\t\t\t\tPlease Enter password at least Upper Case,Lower Case, Speacial Character.");
			 printf("\n\t\t\t\t\t\t\t\t\tPlease enter again.");
        }
    } while (!status);
    do
    {
        printf("\n\n\t\t\t\t\t\t\t\t\tYour Name  = ");
        fflush(stdin);
        fgets(addCustomerInfoInDataBase.customerName,MAX_CUSTOMER_NAME,stdin);
        status = isNameValid(addCustomerInfoInDataBase.customerName);
        if (!status)
        {
            printf("\n\t\t\t\t\t\t\t\t\tCustomer Name contain invalid character. Please enter again.");
        }
	}while(!status);
	
//	printf("\n\t\t\t\t\t\t\t\t\tYour Phone Number = ");
//	fflush(stdin);
//    scanf("%d",&addCustomerInfoInDataBase.ph_no);
       do{
			printf("\n\t\t\t\t\t\t\t\t\t\tYour Phone Number = ");
			fflush(stdin);
			fgets(addCustomerInfoInDataBase.ph_no,MAX_PHNO,stdin);
			status=isValidPhone(addCustomerInfoInDataBase.ph_no);
			if(!status){
			    printf("\n\t\t\t\t\t\t\t\t\t\tPhone number contain only 10 digits. Please enter again.");
			}
			
	}while(!status);
	printf("\n\t\t\t\t\t\t\t\t\tYour Address  = ");
    fflush(stdin);
    fgets(addCustomerInfoInDataBase.customerAddress,MAX_CUSTOMER_ADDRESS,stdin);
	
	
	//Write data in to file
	fwrite(&addCustomerInfoInDataBase,sizeof(addCustomerInfoInDataBase), 1, fp);
	fclose(fp);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t....You are registered Successfully....");
	fclose(fp);
	getch();
}

//Customer Login
void customerLogin()
{
	int found = 0;
	int e = 0;
	char username[MAX_USERNAME],password[MAX_PASSWORD];
	s_CustomerInfo customerInfo = {0};
	FILE *fp = NULL;
    fp = fopen(FILE_NAME1,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
    mainTitle("LOGIN CUSTOMER");
    do{
    	printf("\n\n\t\t\t\t\t\t\t\t\tUsername: ");
		fflush(stdin);
		fgets(username,MAX_USERNAME,stdin);
	  printf("\n\n\t\t\t\t\t\t\t\t\tPassword: ");
    fflush(stdin);
    int i = 0;
    while (i < MAX_PASSWORD - 1) {
        password[i] = getch();
        if (password[i] == '\r') {
            break;
        } else {
            printf("*");
            i++;
        }
    }
    fseek(fp,0,SEEK_SET);
    password[i] = '\0'; 
		while(fread (&customerInfo, sizeof(customerInfo), 1, fp)){
	    	if(strcmp(customerInfo.username,username)==0 && strcmp(customerInfo.password,password)==0){
	    		found = 1;
	    		strcpy(loged_user,username);
	    		break;
			}
		}
	
		if (found) {
	        printf("\n\t\t\t\t\t\t\t\t\tLogin successfully...\n");
	        getch();
	        customerMainMenu();
	        break;
	    } else {
	        printf("\n\t\t\t\t\t\t\t\t\tPlease enter your correct Username and Password.\n");
	        e++;
	         getch();
//        	exit(0);
			
	    }
	}while(e<=2);
		fclose(fp);
}

//Customer main menu
void customerMainMenu(){
	system("cls");
	int choice;
	do{
		mainTitle("MENU");
		printf("\n\n\n\t\t\t\t\t\t\t\t\t1. Manage Profile\n");
		printf("\n\t\t\t\t\t\t\t\t\t2. List Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t3. Search Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t4. Purchase Product\n");
		printf("\n\t\t\t\t\t\t\t\t\t0. Exit\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tChoose from 1 and 4 :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				manageProfile();
				break;
			case 2:
				viewProduct();
				break;
			case 3:
				searchProductByName();
				break;	
			case 4:
				purchaseProduct();
				break;	
			case 0:
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tThank you!!!\n\n\n\n\n");
				getch();
				break;
			default:
				printf("\t\t\t\t\t\t\t\t\t\tInvalid entry. Please enter right option:)");
				getch();	
		}
	}while(choice!=0);
}

//Customer manage profile
void manageProfile(){
	system("cls");
	int choice;
	do{
		mainTitle("MY PROFILE");
		printf("\n\n\n\t\t\t\t\t\t\t\t\t1. My Personal Details\n");
//		printf("\n\t\t\t\t\t\t\t\t\t2. My Orderd list\n");
		printf("\n\t\t\t\t\t\t\t\t\t2. Edit My Profile\n");
		printf("\n\t\t\t\t\t\t\t\t\t3. Change Password\n");
		printf("\n\t\t\t\t\t\t\t\t\t0. Exit\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tChoose from 1 to 3 :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				myDetails();
				break;
//			case 2:
//				purchaseProduct();
//				break;
			case 2:
				editMyProfile();
				break;	
			case 3:
				changeMyPassword();
				break;	
			case 0:
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tThank you!!!\n\n\n\n\n");
				getch();
				break;
			default:
				printf("\t\t\t\t\t\t\t\t\tInvalid entry. Please enter right option:)");
				getch();	
		}
	}while(choice!=0);
	getch();
}

//Display Customer Personal detail
void myDetails(){
	int found = 0;
	unsigned int countCustomer = 1;
	s_CustomerInfo addCustomerInfoInDataBase = {0};
	FILE *fp = NULL;
    fp = fopen(FILE_NAME1,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(1);
    }
    mainTitle("MY DETAILS");
    while (fread (&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp)){
    	if(strcmp(addCustomerInfoInDataBase.username,loged_user)==0){
    		found = 1;
    		break;
		}
	}
	if(found){
		printf("\t\t\t\t\t\t\t\t\tId = %u\n",addCustomerInfoInDataBase.customer_id);
		printf("\t\t\t\t\t\t\t\t\tUsername = %s",addCustomerInfoInDataBase.username);
		printf("\t\t\t\t\t\t\t\t\tPassword = %s\n",addCustomerInfoInDataBase.password);
        
		printf("\t\t\t\t\t\t\t\t\tName = %s",addCustomerInfoInDataBase.customerName);
        printf("\t\t\t\t\t\t\t\t\tPhone Number  = %d\n",addCustomerInfoInDataBase.ph_no);
        printf("\t\t\t\t\t\t\t\t\tAddress = %s\n",addCustomerInfoInDataBase.customerAddress);
	}else{
		printf("\n\t\t\t\t\t\t\t\t\t\tNo Record");
	}
	fclose(fp);
    printf("\n\n\n\t\t\t\t\t\t\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getch();
}

//Edit profile by customer
void editMyProfile(){
	if(loged_user!=""){
		int found = 0;
	    long pos = 0;
	    s_CustomerInfo addCustomerInfoInDataBase = {0};
	    FILE *fp = NULL;
	    mainTitle("UPDATE CUSTOMER");
	    fp = fopen(FILE_NAME1, "rb+");
	    if (fp == NULL) {
	        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
	        exit(1);
	    }
	    while(fread (&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp)){
	    	if(strcmp(addCustomerInfoInDataBase.username,loged_user)==0){
	    		found = 1;
	            pos = ftell(fp) - sizeof(addCustomerInfoInDataBase);
	            
	            printf("\n\t\t\t\t\t\t\t\t\tEnter new details :\n");
	            printf("\n\t\t\t\t\t\t\t\t\tYour Name: ");
	            fflush(stdin);
	            fgets(addCustomerInfoInDataBase.customerName, MAX_CUSTOMER_NAME, stdin);
	            
	            printf("\n\t\t\t\t\t\t\t\t\tYour Phone number: ");
	            fflush(stdin);
	            scanf("%d", &addCustomerInfoInDataBase.ph_no);
	            
	            printf("\n\t\t\t\t\t\t\t\t\tYour Address: ");
	            fflush(stdin);
	            fgets(addCustomerInfoInDataBase.customerAddress, MAX_CUSTOMER_ADDRESS, stdin);
	            
	            fseek(fp, pos, SEEK_SET);
	            fwrite(&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp);
	            break;
			}
		}
		if (found) {
	        printf("\n\t\t\t\t\t\t\t\t\tCustomer details updated successfully.\n");
	    } else {
	        printf("\n\t\t\t\t\t\t\t\t\t\tCustomer not found.\n");
	    }
	    fclose(fp);
	    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to go back to the admin menu.....");
	    fflush(stdin);
	    getch();
	}
}

//Change password by customer
void changeMyPassword() {
    if (loged_user != "") {
        int found = 0;
        long pos = 0;
        s_CustomerInfo addCustomerInfoInDataBase = {0};
        FILE *fp = NULL;
        mainTitle("CHANGE MY PASSWORD");
        fp = fopen(FILE_NAME1, "rb+");
        if (fp == NULL) {
            printf("\n\t\t\t\t\t\t\t\t\tFile is not opened\n");
            exit(1);
        }
        while (fread(&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp)) {
            if (strcmp(addCustomerInfoInDataBase.username, loged_user) == 0) {
                found = 1;
                pos = ftell(fp) - sizeof(addCustomerInfoInDataBase);
                printf("\n\t\t\t\t\t\t\t\t\tEnter new details :\n");
                printf("\n\t\t\t\t\t\t\t\t\t\tNew Password: ");
                fflush(stdin);
                int i = 0;
                while (i < MAX_PASSWORD - 1) {
                    addCustomerInfoInDataBase.password[i] = getch();
                    if (addCustomerInfoInDataBase.password[i] == '\r') {
                        break;
                    } else {
                        printf("*");
                        i++;
                    }
                }
                addCustomerInfoInDataBase.password[i] = '\0';
                fseek(fp, pos, SEEK_SET);
                fwrite(&addCustomerInfoInDataBase, sizeof(addCustomerInfoInDataBase), 1, fp);
                break;
            }
        }
        if (found) {
            printf("\n\t\t\t\t\t\t\t\t\tPassword updated successfully.\n");
        } else {
            printf("\n\t\t\t\t\t\t\t\t\t\tUser not found.\n");
        }
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to go back to the admin menu.....");
        fflush(stdin);
        getch();
        exit(0);
    }
}



void purchaseProduct() {
    int found = 0;
     int total=0;
	char ans;
// int productId = 0;
 char product_name[MAX_PRODUCT_NAME];
    int quantity = 0;
    long pos = 0;
    s_ProductInfo productInfo = {0};
    FILE *fp = NULL;
    FILE *billFile = NULL;

    mainTitle("PURCHASE PRODUCT");

    fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(0);
    }
    billFile = fopen("bill.txt", "a+");
    if (billFile == NULL) {
        fclose(fp);
        printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
        exit(0);
    }

    printf("\n\t\t\t\t\t\t\t\tEnter Product Name to purchase: ");
    fflush(stdin);
 fgets(product_name,MAX_PRODUCT_NAME,stdin);

    while (fread(&productInfo, sizeof(productInfo), 1, fp)) {
        if (strcmp(productInfo.productName,product_name)==0) {
            found = 1;
            pos = ftell(fp) - sizeof(productInfo);

            printf("\n\t\t\t\t\t\t\t\tEnter the quantity to purchase: ");
            scanf("%d", &quantity);

            if (quantity <= productInfo.qty) {
                // Reduce the quantity of the purchased product
                productInfo.qty -= quantity;

                // Move the file pointer to the position where the data needs to be updated
                fseek(fp, pos, SEEK_SET);

                // Write the updated product data to the file
                fwrite(&productInfo, sizeof(productInfo), 1, fp);
                
                char *currentDate = getCurrentDate();
                
                fprintf(billFile, "\nDate: %s \nUsername: %s \nProduct ID: %u \nProduct name: %s \nQuantity: %d \nPrice: %d \nTotal prize: %d\n",
                currentDate,loged_user,productInfo.product_id, productInfo.productName, quantity, productInfo.price,
                (quantity * productInfo.price));
                total+=(quantity * productInfo.price);
                
                printf("\n\t\t\t\t\t\t\t\tPurchase Successful!\n");
// printf("\n\t\t\t\t\t\t\t\t\t\tPurchase successful. Quantity updated.\n");
            } else {
                printf("\n\t\t\t\t\t\t\t\tInsufficient quantity available for purchase.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\n\t\t\t\t\t\t\t\tProduct not found.\n");
    }

    fclose(fp);
    fclose(billFile);
    sd:
 getch();
 printf("\n\n\t\t\t\t\t\t\t\tDo you want to purchase more[Y/N]?? ");
 scanf(" %c",&ans);
 if(toupper(ans)=='Y'){
  purchaseProduct();
 }else if(toupper(ans)=='N'){
  printf("\n\t\t\t\t\t\t\t\t Your toal bill amount: %d",total);
  total=0;
  printf("\n\n\t\t\t\t\t\t\t\tPlease pay bill in cash ane take your products.");
  printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Thank you :) :) ");
// displayBill();
  printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to go back to the main menu.....");
  getch();
 }else{
  printf("\n\t\t\t\t\t\t\t\t\t\tInvalid Input");
  goto sd;
 }
    fflush(stdin);
}

//void displayBill(){
// FILE *billFile = NULL;
// billFile = fopen("bill.txt", "r");
// if (billFile == NULL) {
// fclose(billFile);
// printf("\n\t\t\t\t\t\t\t\t\t\tFile is not opened\n");
// exit(0);
// }
// char line[1000]; // Adjust the size as needed
// int found = 0;
//
// printf("\n\t\t\t\t\t\t\t\t\t*********************************************************************");
// printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tPOOJA SHOP");
// printf("\n\t\t\t\t\t\t\t\t\t*********************************************************************");
// printf("\n\t\t\t\t\t\t\t\t\t%-40s %10s %15s","Description","Qty","Price");
//
//
// while (fgets(line, sizeof(line), billFile)) {
// if (strstr(line, loged_user) != NULL) {
// found = 1;
// while (fgets(line, sizeof(line), billFile) != NULL) {
// printf("Next line: %s", line);
// }
// printf("-------------------------------------------------------------\n");
// }
// }
// while (fgets(line, sizeof(line), billFile)) {
// if(strstr(line, loged_user) != NULL) {
// found = 1;
// if(strcmp(line,loged_user)==0 && strcmp(fgets(line, sizeof(line), billFile),getCurrentDate())==0){
// printf("\n\t\t\t\t\t\t\t\t\t%-40s", line);
// fgets(line, sizeof(line), billFile); // Read the quantity
// printf("%10s", line);
// fgets(line, sizeof(line), billFile); // Read the product name
// printf("%15s", line);
// fgets(line, sizeof(line), billFile); // Read the price
// printf("%15s", line);
// }
//   
// }
// }
//
// getch();
// if (!found) {
// printf("\n\t\t\t\t\t\t\t\t\t\tNo bill found for User: %s\n", loged_user);
// }
//
// fclose(billFile);
//
//}


