#pragma once
#define FILESTUD "studdata.dat"
#define FILEMANA "manadata.dat"

void save();
void load();
void clearall();  //删除缓存在内存的记录
void refreshall();  //刷新缓存