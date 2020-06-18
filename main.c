#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
	char first[10];
	char last[10];
	int bats, hits, walks, runs;
	float average;
};

int main()
{
	struct Player team[19];
	for (int i = 0; i < 19; i++)
	{
		struct Player player;
		strcpy(player.first, "");
		strcpy(player.last, "");
		player.bats = 0;
		player.hits = 0;
		player.walks = 0;
		player.runs = 0;
		team[i] = player;
	}

	FILE *fp;
	int n;
	char first[10];
	char last[10];
	int bats;
	int hits;
	int walks;
	int runs;
	fp = fopen("team.txt", "r");

	while (fscanf(fp, "%d %s %s %u %u %u %u", &n, first, last, &bats,
				  &hits, &walks, &runs) == 7)
	{
		if (team[n].first[0] == '\0')
		{
			strncpy(team[n].first, first, 10);
			strncpy(team[n].last, last, 10);
		}
		team[n].bats += bats;
		team[n].hits += hits;
		team[n].walks += walks;
		team[n].runs += runs;
	}

	printf("Player stats - bats, hits, walks, runs, average \n");
	for (int i = 0; i < 18; i++)
	{
		if (team[i].bats != 0)
		{
			team[i].average = team[i].hits / (float)team[i].bats;
			printf("%s %s %u %u %u %u %.3f \n", team[i].first,
				   team[i].last, team[i].bats, team[i].hits, team[i].walks,
				   team[i].runs, team[i].average);

			team[18].bats += team[i].bats;
			team[18].hits += team[i].hits;
			team[18].runs += team[i].runs;
			team[18].walks += team[i].walks;
		}
	}

	team[18].average = team[18].hits / (float)team[18].bats;

	printf("Team stats - first, last, bats, hits, walks, runs, average \n");
	printf("%s %s %u %u %u %u %.3f\n", team[18].first,
		   team[18].last, team[18].bats, team[18].hits, team[18].walks,
		   team[18].runs, team[18].average);

	fclose(fp);

	return 0;
}
