#include "../includes/executor.h"

// РЕАЛИЗОВАТЬ ПОЛНОЕ ЧТЕНИЕ ФАЙЛА С КАРТОЙ
// ОПРЕДЕЛИТЬ РАЗМЕР МАССИВА
// ЧЕРЕЗ gnl СЧИТАТЬ ВСЕ СТРОКИ ИЗ ФАЙЛА
char	**parse_map()
{
	char	**map;
	int		fd;
	
	fd = open("map.cub", O_RDONLY);		// открываем файл с картой
	map = malloc(sizeof(char*) * 100);	// массив для строк карты
	for(int i=0; i<100; i++){
		get_next_line(fd, &map[i]);
		//printf("%s",map[i]);
	}
	return map;
}
