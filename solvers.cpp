
void advance_FTCS(parameters param, node &myGrid, std::size_t &time_step)
{
    dirichletX(myGrid.phinp1, myGrid.nB, myGrid.nE, 10.0);
    dirichletY(myGrid.phinp1, myGrid.nB, myGrid.nE, 10.0);

    for(std::size_t i=myGrid.nB[0]+1; i<=myGrid.nE[0]-1; i++)
        for(std::size_t j=myGrid.nB[1]+1; j<=myGrid.nE[1]-1; j++)
        {
            myGrid.phinp1(i,j) = myGrid.phin(i,j) + 0.25*param.cfl_FTCS*( myGrid.phin(i+1,j) + myGrid.phin(i-1,j) 
                                    + myGrid.phin(i,j+1) + myGrid.phin(i,j-1) - 4.0*myGrid.phin(i,j) );
        }

    for(std::size_t i=myGrid.nB[0]; i<=myGrid.nE[0]; i++)
        for(std::size_t j=myGrid.nB[1]; j<=myGrid.nE[1]; j++)
            myGrid.phin(i,j) = myGrid.phinp1(i,j);
    
    time_step++;
}

