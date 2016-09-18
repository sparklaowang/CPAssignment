long double power(long double under , int index)
{
	switch(index)
	{
		case 0 :
			return(1);
		break;
		case 1: 
			return(under);
		break;
		default:
		{
			if(0 == (index % 2))
				return(power(under,index/2)*power(under,index/2));
			else
				return(under*power(under,index-1));
		}
		break;
	}
}
