#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct team {
    char name[10];
    int points,goalDifference;
};

typedef struct team UEFA;

int main () {
    int t;
    scanf("%d",&t);
    while (t--) {
        char home_team[10],away_team[10];
        int i,j,home_goal,away_goal;
        UEFA teams[4],temp;  
        bool homeTeam_found , awayTeam_found;

        for(i=0;i<4;i++) {
            teams[i].name[0] = '#';
            teams[i].points = 0;
            teams[i].goalDifference =0;
        }

        for(i=0;i<12;i++) {
            scanf("%s %d vs. %d %s",home_team,&home_goal,&away_goal,away_team);
            j=0;
            homeTeam_found = false;
            awayTeam_found = false;
            while (j<4) {
                
                if (!homeTeam_found && (teams[j].name[0]=='#' || !strcmp(teams[j].name , home_team))) { 
                    strcpy(teams[j].name , home_team);
                    if (home_goal > away_goal) {
                        teams[j].points += 3;
                    }
                    else if (home_goal == away_goal) {
                        teams[j].points += 1;
                    }
                    teams[j].goalDifference += (home_goal - away_goal);
                    homeTeam_found = true;  
                    j++;                  
                }
                if (!awayTeam_found && (teams[j].name[0]=='#' || !strcmp(teams[j].name , away_team))) {
                    strcpy(teams[j].name , away_team);
                    if (away_goal > home_goal) {
                        teams[j].points +=3;
                    }
                    else if (home_goal == away_goal) {
                        teams[j].points +=1;
                    }
                    teams[j].goalDifference += (away_goal - home_goal);
                    awayTeam_found = true;
                }
                if(homeTeam_found && awayTeam_found) {
                    break;
                }
                j++;
            }
        }

        for(i=0;i<2;i++) {
            for(j=i+1;j<4;j++) {
                if ((teams[j].points > teams[i].points) || ((teams[j].points == teams[i].points) && (teams[j].goalDifference > teams[i].goalDifference))) {
                    temp = teams[i];
                    teams[i] = teams[j];
                    teams[j]= temp;
                }
            }
        }

        printf("%s %s\n",teams[0].name , teams[1].name);
    }
    return 0;
}
