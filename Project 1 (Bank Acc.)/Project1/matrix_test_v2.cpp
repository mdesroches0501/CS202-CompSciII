




// header goes here
int main(int argc, char *argv[])
{
// 	int i, j, k;
	int m, n;
	char let_x:
	char_file1[20];
	ifstream infile;

	if (argc<3)
	{
		strcpy(file1, argv[2]);
		strcat(file1, ".mtx)");
		infile.open(file1);

		if (!infile)
		{
			cout << "\nError opening file: " << file1 << "\n\n";
			return 0;
		}
	}

	infile >> m >> let_x >> n;

	Matrix mat1(m, n);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			infile >> k;
			mat1.set(i, j, l);
		}
	}

	mat1.display();

	infile.close();

	return 0;
}
	
