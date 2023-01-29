#include <stdio.h>

typedef struct {
  int team_num;
  int time_delay;
  int prob_score[9];
  int score;
  int exist;
} team_info;

team_info buf[100];

void sort(team_info *arr, int start, int end);
void merge(team_info *arr, int start, int mid, int end);
int comp(team_info a, team_info b);

int main() {
  int tc;
  char buf[100];
  scanf("%d", &tc);
  getchar();
  getchar();

  team_info infos[100];

  int team, prob, time;
  char L;

  while (tc-- > 0) {
	// Initiallize team info
    for (int i = 0; i < 100; i++) {
      infos[i].team_num = i + 1;
      for (int j = 0; j < 9; j++)
        infos[i].prob_score[j] = 0;

      infos[i].time_delay = 0;
      infos[i].score = 0;
      infos[i].exist = 0;
    }

    while (fgets(buf, 100, stdin) != NULL) {
      if (buf[0] == '\0' || buf[0] == '\n') {
        break;
      }
      sscanf(buf, "%d %d %d %c\n", &team, &prob, &time, &L);
      if (infos[team - 1].exist == 0)
        infos[team - 1].exist = 1;
      if (L == 'R' || L == 'U' || L == 'E')
        continue;

      if (L == 'I' && infos[team-1].prob_score[prob-1] >= 0) {
        infos[team - 1].prob_score[prob - 1] += 20;
      } else if (L == 'C' && infos[team-1].prob_score[prob-1] !=-1) {
        infos[team - 1].time_delay += infos[team - 1].prob_score[prob - 1];
        infos[team - 1].time_delay += time;
        infos[team - 1].prob_score[prob - 1] = -1;
        infos[team - 1].score += 1;
      }
    }

    sort(infos, 0, 100);

    for (int i = 0; i < 100; i++) {
      if (infos[i].exist == 0)
        continue;
      printf("%d %d %d\n", infos[i].team_num, infos[i].score,
             infos[i].time_delay);
    }
    if (tc != 0)
    	printf("\n");
  }

  return 0;
}
void sort(team_info *arr, int start, int end) {
  if (start + 1 >= end)
    return;
  int mid = (start + end) / 2;

  sort(arr, start, mid);
  sort(arr, mid, end);
  merge(arr, start, mid, end);
}
void merge(team_info *arr, int start, int mid, int end) {

  int idx1 = start;
  int idx2 = mid;
  int idx = start;

  while (idx1 < mid && idx2 < end) {
    int a = comp(arr[idx1], arr[idx2]);
    if (a <= 0) {
      buf[idx++] = arr[idx1];
      idx1++;
    } else {
      buf[idx++] = arr[idx2];
      idx2++;
    }
  }

  if (idx1 == mid) {
    while (idx2 < end) {
      buf[idx++] = arr[idx2];
      idx2++;
    }
  } else {
    while (idx1 < mid) {
      buf[idx++] = arr[idx1];
      idx1++;
    }
  }
  for (int i = start; i < end; i++)
    arr[i] = buf[i];

  return;
}

int comp(team_info a, team_info b) {
  if (a.score == b.score)
    return a.time_delay - b.time_delay;

  else
    return b.score - a.score;
}