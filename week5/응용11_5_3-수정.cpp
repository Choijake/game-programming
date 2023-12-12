#include <stdio.h>

void print_ascii_art();  

void number_to_hangul(unsigned long money);

int main(void)
{
    unsigned long money;

    print_ascii_art();
    scanf("%ld", &money);
    printf("\nȭ�����\n");

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
    char *korean_digits[] = {"��", "��", "��", "��", "��", "��", "��", "ĥ", "��", "��"};
    printf("%s", korean_digits[digit]);
}
//�Էµ� �ݾ��� ū �������� ���� ������ ������ ��ȯ�Ͽ� �ѱ۷� ���
void number_to_hangul(unsigned long money)
{
    unsigned long num1, num2, temp;
    unsigned long m_unit[] = {100000000, 10000, 1};
    unsigned long m_unit01[] = {1000, 100, 10};
    int i, j;
    
	//�ѱ۷� ǥ���� �� ����ϴ� ������� ���ڵ��� ����
    char *unit01[] = {"��", "��", "��"};
    char *unit02[] = {"õ", "��", "��"};

	//������ �̿��Ͽ� ū �������� ���� �������� �ݺ�
    for (i = 0; i < 3; i++)
    {
    	//num1�� �ش� ������ �ݾ��� ����
        num1 = money / m_unit[i];
        if (!num1)
            continue;

        temp = num1;
        for (j = 0; j < 3; j++)
        {
        	//�ش� ������ ���� ���� ����Ͽ� num2�� ����
            num2 = num1 / m_unit01[j];

            if (!num2)
                continue;

			//num2�� 0�� �ƴϸ� �ش� ������ �ѱ� ǥ���� �ڸ����� �ش��ϴ� �ѱ��� ���
            print_korean_digit(num2);
            printf("%s", unit02[j]);

            num1 = num1 - num2 * m_unit01[j];
        }
        print_korean_digit(num1);
        printf("%s ", unit01[i]);
		//�Է¹��� �ݾ׿��� ��ȯ�� �ݾ��� ����, ���� ������ ����� ���� money�� ����
        money = money - temp * m_unit[i];
    }
    printf("\n");
}

