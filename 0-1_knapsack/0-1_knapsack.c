void read_data(int(*quiz)[COLUMN_NUM], const char* fileDir)
{
	FILE* fp;
	char buffer[DATA_SIZE * COLUMN_NUM];
	char* ptr;
	int i = 0, j = 0;

	fp = fopen(fileDir, "r");

	if (fp == NULL)
	{
		puts("data file open failed!!");

		return;
	}

	for (i = 0; i < DATA_SIZE; i++)
	{
		fgets(buffer, DATA_SIZE * COLUMN_NUM, fp);
		ptr = strtok(buffer, ",");
		j = 0;

		while (ptr != NULL)
		{
			quiz[i][j] = atof(ptr);
			printf("%d\n",quiz[i][j]);
			ptr = strtok(NULL, ",");
			j++;
		}
	}

	fclose(fp);
}