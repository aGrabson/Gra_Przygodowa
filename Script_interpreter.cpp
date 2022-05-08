#include "Script_interpreter.h"

Script_interpreter::Script_interpreter()
{
	operation = NOP;
	numberOfObjects = 0;
	index = 0;
	type = NOP;
	tabsize = 0;
	stringnum = "1234567890";
	strbuffX.clear();
	strbuffY.clear();
}
vector<Script_values> Script_interpreter::readFile(string path)
{	

	std::fstream file;
	file.open(path,ios::in);
	if (!file.good())
	{
		std::cout << "No such file\n";
	}
	while (!file.eof())
	{
		file >> tmp;
		//cout << tmp << endl;
		if (oneObjectOperations())
			continue;
		if (tabObjectOperations())
			continue;
		if (readOperation())
			break;
		
	}
	file.close();
	return valuesTab;
}

bool Script_interpreter::oneObjectOperations()
{
	if (type == ONEOBJECT)
	{
		if (operation == ONEOBJECT)
		{
			index++;
			numberOfObjects++;
		}
		else if (operation == SETOFFSETX)
		{
			values.offsetx = stod(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == SETOFFSETY)
		{
			values.offsety = stod(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == SETCOLUMN)
		{
			values.column = stoi(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == SETTEXTURESCALEX)
		{
			values.texture_scale_X = stod(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == SETTEXTURESCALEY)
		{
			values.texture_scale_Y= stod(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == SETROW)
		{
			values.row = stoi(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == SETPOSX)
		{
			values.posx = stoi(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == SETPOSY)
		{
			values.posy = stoi(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == CREATE)
		{
			valuesTab.push_back(values);
			operation = NOP;
			return true;
		}
		else if (operation == SETTEXTURE)
		{
			values.texture_name = tmp;
			operation = NOP;
			return true;
		}
		else if (operation == SETSCALEX)
		{
			values.colision_x_scale =stod(tmp);
			operation = NOP;
			return true;
		}
		else if (operation == SETSCALEY)
		{
			values.colision_y_scale = stod(tmp);
			operation = NOP;
			return true;
		}

	}
	return false;
}

bool Script_interpreter::tabObjectOperations()
{
	if (type == TABOBJECT)
	{
		if (operation == SETSIZE)
		{
			int number = stoi(tmp);
			tabsize = number;
			for (int i = 0; i < number; i++)
			{
				valuesTab.push_back(Script_values());
			}
			index += number;
			numberOfObjects += number;
			operation = NOP;
			return true;
		}
		else if (operation ==SETOFFSETX)
		{
			int tmpindex = index - tabsize;
			for (int i = 0; i < tabsize; i++)
			{
				valuesTab[tmpindex].offsetx = stod(tmp);
				tmpindex++;
			}
			operation = NOP;
			return true;
		}
		else if (operation == SETOFFSETY)
		{
			int tmpindex = index - tabsize;
			for (int i = 0; i < tabsize; i++)
			{
				valuesTab[tmpindex].offsety = stod(tmp);
				tmpindex++;
			}
			operation = NOP;
			return true;
		}
		else if (operation == SETSECTOR)
		{
			int XYType = 1;
			int tmpindex = index - tabsize;
			for (int i = 0; i < tmp.size(); i++)
			{
				for (int j = 0; j < stringnum.size(); j++)
				{
					if (tmp[i] == stringnum[j])
					{

						if (XYType == 1)
						{

							strbuffX += tmp[i];
						}
						else
						{

							strbuffY += tmp[i];
						}

						break;
					}
					else if (tmp[i] == ',')
					{
						XYType = 2;
					}
					else if (tmp[i] == ';')
					{
						valuesTab[tmpindex].column = stoi(strbuffX);
						valuesTab[tmpindex].row = stoi(strbuffY);
						strbuffX.clear();
						strbuffY.clear();
						tmpindex++;
						XYType = 1;
						break;
					}
				}
			}
			operation = NOP;
			return true;
		}
		else if (operation == SETTEXTURE)
		{
			int tmpindex = index - tabsize;
			for (int i = 0; i < tabsize; i++)
			{
				valuesTab[tmpindex].texture_name = tmp;
				tmpindex++;
			}
			operation = NOP;
			return true;
		}
		else if (operation == SETTEXTURESCALEX)
		{
			int tmpindex = index - tabsize;
			for (int i = 0; i < tabsize; i++)
			{
				valuesTab[tmpindex].texture_scale_X = stod(tmp);
				tmpindex++;
			}
			operation = NOP;
			return true;
		}
		else if (operation == SETTEXTURESCALEY)
		{
			int tmpindex = index - tabsize;
			for (int i = 0; i < tabsize; i++)
			{
				valuesTab[tmpindex].texture_scale_Y = stod(tmp);
				tmpindex++;
			}
			operation = NOP;
			return true;
		}
		else if (operation == SETPOSITION)
		{
			int XYType = 1;

			int tmpindex = index - tabsize;
			for (int i = 0; i < tmp.size(); i++)
			{
				for (int j = 0; j < stringnum.size(); j++)
				{
					if (tmp[i] == stringnum[j])
					{

						if (XYType == 1)
						{

							strbuffX += tmp[i];
						}
						else
						{

							strbuffY += tmp[i];
						}

						break;
					}
					else if (tmp[i] == ',')
					{
						XYType = 2;
					}
					else if (tmp[i] == ';')
					{
						valuesTab[tmpindex].posx = stoi(strbuffX);
						valuesTab[tmpindex].posy = stoi(strbuffY);
						strbuffX.clear();
						strbuffY.clear();
						tmpindex++;
						XYType = 1;
						break;
					}
				}
			}

			operation = NOP;
			return true;
		}
		else if (operation == SETSCALEX)
		{
			int tmpindex = index - tabsize;
			for (int i = 0; i < tabsize; i++)
			{
				valuesTab[tmpindex].colision_x_scale = stod(tmp);
				tmpindex++;
			}
			operation = NOP;
			return true;
		}
		else if (operation == SETSCALEY)
		{
			int tmpindex = index - tabsize;
			for (int i = 0; i < tabsize; i++)
			{
				valuesTab[tmpindex].colision_y_scale = stod(tmp);
				tmpindex++;
			}
			operation = NOP;
			return true;
		}
	}
	return false;
}

bool Script_interpreter::readOperation()
{
	if (tmp == "Object")
	{
		operation = ONEOBJECT;
		type = ONEOBJECT;
	}
	else if (tmp == "ObjectTab")
	{
		operation = TABOBJECT;
		type = TABOBJECT;
	}
	else if (tmp == "sector:")
		operation = SETSECTOR;
	else if (tmp == "position:")
		operation = SETPOSITION;
	else if (tmp == "size:")
		operation = SETSIZE;
	else if (tmp == "column:")
		operation = SETCOLUMN;
	else if (tmp == "row:")
		operation = SETROW;
	else if (tmp == "texture:")
		operation = SETTEXTURE;
	else if (tmp == "posx:")
		operation = SETPOSX;
	else if (tmp == "posy:")
		operation = SETPOSY;
	else if (tmp == "colision_x_scale:")
		operation = SETSCALEX;
	else if (tmp == "colision_y_scale:")
		operation = SETSCALEY;
	else if (tmp == "}")
		operation = CREATE;
	else if (tmp == "texturescale_X:")
		operation = SETTEXTURESCALEX;
	else if (tmp == "texturescale_Y:")
		operation = SETTEXTURESCALEY;
	else if (tmp == "offsetX:")
		operation = SETOFFSETX;
	else if (tmp == "offsetY:")
		operation = SETOFFSETY;
	else if (tmp == "End")
		return true;
	return false;
}
