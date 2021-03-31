void writeSolutionfile(node &myGrid, int time_step)
{
    FILE* out;
	char fileName[150];

	if (!fileName)
	{
		fprintf(stderr, "Memory Allocation failure " );
		//exit(0);
	}
	sprintf(fileName,"./Results/Solution%04d.txt", time_step);

	out = fopen(fileName,"w");

	//fprintf(out, " %s %d \n", "XGridPoints:", nx );
	//fprintf(out, " %s %d \n", "YGridPoints:", ny ) ;

	for(std::size_t i=myGrid.nB[0]; i<=myGrid.nE[0]; i++)
    {
        for(std::size_t j=myGrid.nB[1]; j<=myGrid.nE[1]; j++)
        {
            fprintf(out,"%.10lf %.10lf %.10lf %.10lf \n",myGrid.coordX[i], myGrid.coordY[j], myGrid.phi_exact(i,j), myGrid.phin(i,j) ) ;
        }
    }
	fclose(out); 
}