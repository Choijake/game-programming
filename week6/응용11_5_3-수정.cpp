#include <stdio.h>

void print_ascii_art();  

void number_to_hangul(unsigned long money);

int main(void)
{
    unsigned long money;

    print_ascii_art();
    scanf("%ld", &money);
    printf("\n화폐단위\n");

    number_to_hangul(money);

    return 0;
}

void print_ascii_art()
{
    printf(" /$$$$$$$$                                  /$$$$$$$$ /$$                        /$$$$$$                                                /$$           /$$\n");
    printf("|__  $$__/                                 |__  $$__/| $$                       /$$__  $$                                              | $$          | $$\n");
    printf("   | $$ /$$   /$$  /$$$$$$   /$$$$$$          | $$   | $$$$$$$   /$$$$$$       | $$  \\ $$ /$$$$$$/$$$$   /$$$$$$  /$$   /$$ /$$$$$$$  /$$$$$$        | $$\n");
    printf("   | $$| $$  | $$ /$$__  $$ /$$__  $$         | $$   | $$__  $$ /$$__  $$      | $$$$$$$$| $$_  $$_  $$ /$$__  $$| $$  | $$| $$__  $$|_  $$_/        | $$\n");
    printf("   | $$| $$  | $$| $$  \\ $$| $$$$$$$$         | $$   | $$  \\ $$| $$$$$$$$      | $$__  $$| $$ \\ $$ \\ $$| $$  \\ $$| $$  | $$| $$  \\ $$  | $$          |__/\n");
    printf("   | $$| $$  | $$| $$  | $$| $$_____/         | $$   | $$  | $$| $$_____/      | $$  | $$| $$ | $$ | $$| $$  | $$| $$  | $$| $$  | $$  | $$ /$$          \n");
    printf("   | $$|  $$$$$$$| $$$$$$$/|  $$$$$$$         | $$   | $$  | $$|  $$$$$$$      | $$  | $$| $$ | $$ | $$|  $$$$$$/|  $$$$$$/| $$  | $$  |  $$$$/       /$$\n");
    printf("   |__/ \\____  $$| $$____/  \\_______/         |__/   |__/  |__/ \\_______/      |__/  |__/|__/ |__/ |__/ \\______/  \\______/ |__/  |__/   \\___/        |__/\n");
    printf("        /$$  | $$| $$                                                                                                                                               \n");
    printf("       |  $$$$$$/| $$                                                                                                                                               \n");
    printf("        \\______/ |__/                    																															\n");
}



void print_korean_digit(int digit)
{
    char *korean_digits[] = {"영", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};
    printf("%s", korean_digits[digit]);
}
//입력된 금액을 큰 단위부터 작은 단위로 나누어 변환하여 한글로 출력
void number_to_hangul(unsigned long money)
{
    unsigned long num1, num2, temp;
    unsigned long m_unit[] = {100000000, 10000, 1};
    unsigned long m_unit01[] = {1000, 100, 10};
    int i, j;
    
	//한글로 표현할 때 사용하는 단위들과 숫자들을 저장
    char *unit01[] = {"억", "만", "원"};
    char *unit02[] = {"천", "백", "십"};

	//루프를 이용하여 큰 단위부터 작은 단위까지 반복
    for (i = 0; i < 3; i++)
    {
    	//num1에 해당 단위의 금액을 저장
        num1 = money / m_unit[i];
        if (!num1)
            continue;

        temp = num1;
        for (j = 0; j < 3; j++)
        {
        	//해당 단위로 나눈 몫을 계산하여 num2에 저장
            num2 = num1 / m_unit01[j];

            if (!num2)
                continue;

			//num2가 0이 아니면 해당 단위의 한글 표현과 자릿수에 해당하는 한글을 출력
            print_korean_digit(num2);
            printf("%s", unit02[j]);

            num1 = num1 - num2 * m_unit01[j];
        }
        print_korean_digit(num1);
        printf("%s ", unit01[i]);
		//입력받은 금액에서 변환한 금액을 빼고, 다음 단위의 계산을 위해 money를 갱신
        money = money - temp * m_unit[i];
    }
    printf("\n");
}

