#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

char *questions[] = {
    "What is the capital of France?\nA) Berlin B) Paris C) Madrid",
    "How many continents are there?\nA) 5 B) 6 C) 7",
    "What color is the sky on a clear day?\nA) Green B) Blue C) Red",
    "What is the largest ocean on Earth?\nA) Atlantic Ocean B) Indian Ocean C) Pacific Ocean",
    "Who wrote the play 'Romeo and Juliet'?\nA) William Shakespeare B) Charles Dickens C) Mark Twain",
    "What is the smallest planet in our solar system?\nA) Mercury B) Mars C) Venus",
    "What is the name of the fairy in 'Peter Pan'?\nA) Tinker Bell B) Wendy Darling C) Alice",
    "In which country would you find the Great Wall?\nA) Japan B) China C) India",
    "What is the main ingredient in guacamole?\nA) Avocado B) Tomato C) Onion",
    "How many days are in a leap year?\nA) 365 B) 366 C) 370",
    "Which fruit is known for keeping the doctor away when eaten every day?\nA) Banana B) Apple C) Orange",
    "What is the longest river in the world?\nA) Amazon River B) Nile River C) Yangtze River",
    "What is the name of the famous wizarding school in 'Harry Potter'?\nA) Hogwarts B) Beauxbatons C) Durmstrang",
    "What is the largest mammal in the world?\nA) Elephant B) Blue Whale C) Giraffe",
    "What is the boiling point of water in Celsius?\nA) 90°C B) 100°C C) 110°C",
    "What animal is known as the king of the jungle?\nA) Tiger B) Lion C) Elephant",
    "What is the most common blood type?\nA) A B) B C) O",
    "What is the national sport of Japan?\nA) Judo B) Karate C) Sumo Wrestling",
    "Which planet is known as the Red Planet?\nA) Mars B) Venus C) Earth",
    "How many sides does a triangle have?\nA) 2 B) 3 C) 4",
    "What is the chemical symbol for gold?\nA) Ag B) Au C) Pb",
    "Which planet is closest to the sun?\nA) Earth B) Mercury C) Venus",
    "Who invented the telephone?\nA) Thomas Edison B) Nikola Tesla C) Alexander Graham Bell",
    "What is the capital of Canada?\nA) Toronto B) Montreal C) Ottawa",
    "What is the largest desert in the world?\nA) Sahara Desert B) Arctic Desert C) Gobi Desert",
    "Who painted the 'Mona Lisa'?\nA) Vincent van Gogh B) Leonardo da Vinci C) Pablo Picasso",
    "What is the hardest natural substance on Earth?\nA) Gold B) Diamond C) Iron",
    "What is the square root of 144?\nA) 10 B) 12 C) 14",
    "In which year did the Titanic sink?\nA) 1910 B) 1912 C) 1920",
    "Who wrote 'The Great Gatsby'?\nA) F. Scott Fitzgerald B) Ernest Hemingway C) Mark Twain",
    "Which animal is known for its black and white stripes?\nA) Zebra B) Tiger C) Panda",
    "What is the capital of Australia?\nA) Sydney B) Melbourne C) Canberra",
    "What is the longest river in North America?\nA) Mississippi River B) Colorado River C) Missouri River",
    "In which year did World War II end?\nA) 1943 B) 1945 C) 1950",
    "Who is known as the 'Father of Computers'?\nA) Charles Babbage B) Alan Turing C) John von Neumann",
    "What is the largest island in the world?\nA) Australia B) Greenland C) New Guinea",
    "What is the primary ingredient in traditional Japanese miso soup?\nA) Tofu B) Miso Paste C) Seaweed",
    "What is the smallest country in the world by land area?\nA) Monaco B) Vatican City C) San Marino",
    "What is the name of the largest volcano in the world?\nA) Mount Kilimanjaro B) Mount Fuji C) Mauna Loa",
    "Who developed the theory of relativity?\nA) Isaac Newton B) Albert Einstein C) Nikola Tesla",
    "Which element has the highest electronegativity?\nA) Oxygen B) Fluorine C) Chlorine",
    "Who is credited with developing the first successful polio vaccine?\nA) Louis Pasteur B) Edward Jenner C) Jonas Salk",
    "Which scientist is known for the discovery of the electron?\nA) Albert Einstein B) Niels Bohr C) J.J. Thomson",
    "What is the longest-running novel ever published?\nA) Don Quixote B) War and Peace C) In Search of Lost Time",
    "Which battle marked the turning point of the American Civil War?\nA) Battle of Gettysburg B) Battle of Antietam C) Battle of Fort Sumter",
    "What is the name of the first artificial satellite launched into space?\nA) Sputnik 1 B) Voyager 1 C) Apollo 11",
    "What was the original name of New York City?\nA) New Amsterdam B) New Paris C) New London",
    "What was the first country to grant women the right to vote?\nA) United States B) United Kingdom C) New Zealand",
    "What year did the first successful human heart transplant occur?\nA) 1959 B) 1967 C) 1971",
    "Who is the only person to have won two Nobel Prizes in different scientific fields?\nA) Albert Einstein B) Marie Curie C) Linus Pauling"
};

char correct_answers[] = {
    'B', 'C', 'B', 'C', 'A', 'A', 'A', 'B', 'A', 'B', 'B', 'B', 'A', 'B', 'B', 'B', 'C', 'C', 'A', 'B',
    'B', 'B', 'C', 'C', 'B', 'B', 'B', 'B', 'B', 'A', 'A', 'C', 'C', 'B', 'A', 'A', 'B', 'B', 'C', 'B',
    'B', 'C', 'C', 'C', 'A', 'A', 'A', 'C', 'B', 'B'};

int question_history[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int verification(int number) {
    for(int i=0;i<10;i++)
        if(number == question_history[i]) return 0;
    return 1;
}

void clear() {
    system("cls");
}

void header() {
    printf("=============================\n");
    printf("   Welcome to Trivia Game!\n");
    printf("=============================\n");
    printf("1.New Game\n");
    printf("2.Continue\n");
    printf("3.Exit\n");
}

typedef struct board {
    char name[31];
    int score;
}board;

board leaderboard[10];

void leaderboard_print() {
    printf("=====LEADERBOARD=====\n");
    for(int i=0;i<10;i++) {
        if(!leaderboard[i].score) break;
        printf("%d.%s - %d\n",i+1,leaderboard[i].name, leaderboard[i].score);
    }
    printf("=====================\n");
}

int main() {
    srand(time(NULL));
    int instruction,i,random_number,score = 0,starting_point=0,qdiff;
    char user_answer[10];
    header();
    scanf("%d",&instruction);
    if(instruction == 3) {
        printf("Goodbye!");
        return 0;
    }
    system("cls");
    if(instruction == 2) {
        FILE *pQF = fopen("question_history.txt","r");
        for(i=0;i<10;i++)
            fscanf(pQF,"%d",&question_history[i]);
        fscanf(pQF,"%d",&starting_point);
        fscanf(pQF,"%d",&score);
        fclose(pQF);
        printf("\033[1;35m");
        if(starting_point==0) printf("No game saved!\n");
        else printf("Continuing previous game...\n");
        printf("\033[0m");
        Sleep(2000);
    }
    for(i=starting_point; i < 10; i++) {
        if(i==0) printf("Starting new game...\n");
        Sleep(1000);
        random_number = -1;
        printf("Choose the difficulty of your question ");
        printf("\033[1;35m");
        printf("(1, 2 or 3):");
        printf("\033[0m");
        scanf("%d", &qdiff);
        if (qdiff == 1)
            while(verification(random_number)==0)
                random_number = rand()%20;
        else if (qdiff == 2)
            while(verification(random_number)==0)
                random_number = 20 + rand()%20;
        else if (qdiff == 3)
            while(verification(random_number)==0)
                random_number = 40 + rand()%10;
        question_history[i] = random_number;
        Sleep(1000);
        printf("%d. %s\n", i + 1, questions[random_number]);
        Sleep(1000);
        printf("Your answer: ");
        scanf(" %s", &user_answer);
        user_answer[0] = toupper(user_answer[0]);
        if(user_answer[0] == correct_answers[random_number]){
            printf("\033[0;32m");
            printf("Correct!\n\n");
            printf("\033[0m");
            if(random_number < 20) score = score + 1;
            else if(random_number < 40) score = score + 2;
            else score = score + 3;
        }
        else if(strcmp(user_answer,"Exit")==0) {
            question_history[i] = -1;
            FILE *pQF = fopen("question_history.txt","w");
            for(int i=0;i<10;i++)
                fprintf(pQF, "%d ", question_history[i]);
            fprintf(pQF, "\n%d\n%d",i, score);
            fclose(pQF);
            printf("\033[0;35m");
            printf("Answers saved. Exiting...");
            Sleep(1000);
            return 0;
        }
        else {
            printf("\033[1;31m");
            printf("Wrong!\n");
            printf("\033[0m");
            printf("Correct answer: %c\n\n", correct_answers[random_number]);
        }
    }
    printf("Your score: %d\n", score);
    if(score==30) printf("WOW! YOU ARE A GENIUS!\n");
    Sleep(3000);
    system("cls");
    FILE *pQF = fopen("question_history.txt","w");
    for(int i=0;i<10;i++)
        fprintf(pQF, "%d ", -1);
    fprintf(pQF, "\n%d\n%d",0,0);
    fclose(pQF);
    pQF = fopen("question_history.txt","w");
    for(int i=0;i<10;i++)
        fprintf(pQF, "%d ", -1);
    fprintf(pQF, "\n%d\n%d",0,0);
    fclose(pQF);
    for(i=0;i<10;i++) {
        leaderboard[i].score = NULL;
    }
    FILE *pLF = fopen("leaderboard.txt","r");
    char line[50]; i=0;
    while(fgets(line, 50, pLF)) {
        char *p = strtok(line, " ");
        strcpy(leaderboard[i].name,p);
        p = strtok(NULL, " ");
        int s = atoi(p);
        leaderboard[i].score = s;
        i++;
    }
    fclose(pLF);
    if(score>leaderboard[9].score) {
        printf("You have reached the ");
        printf("\033[0;33m");
        printf("leaderboard");
        printf("\033[0m");
        printf("!\nPlease enter the username you want to be displayed:\n(NO SPACES, 30 CHARACTERS MAX)\n");
        char username[31];
        scanf("%s",username);
        i = 8;
        while(score > leaderboard[i].score && i>=0) {
            leaderboard[i+1] = leaderboard[i];
            i--;
        }
        strcpy(leaderboard[i+1].name,username);
        leaderboard[i+1].score = score;
        FILE *pLF = fopen("leaderboard.txt","w");
        printf("=====LEADERBOARD=====\n");
        for(int i=0;i<10;i++) {
            if(!leaderboard[i].score) break;
            printf("%d.%s - %d\n",i+1,leaderboard[i].name, leaderboard[i].score);
            fprintf(pLF, "%s %d\n", leaderboard[i].name, leaderboard[i].score);
        }
        printf("=====================\n");
        fclose(pLF);
    }
    else {
        printf("Too low. Try again some other time!\n\n");
        leaderboard_print();
    }
    Sleep(10000);
    char ex;
    scanf("ENTER to exit%c", &ex);
    return 0;
}
//could work on the main(less spaghetti code -> more functions)