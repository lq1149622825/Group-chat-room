#定义一个SRC_LIST变量 包含该目录下的所有文件
aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_LIST)
aux_source_directory(./model MD_LIST)
aux_source_directory(./redis RD_LIST)

#指定可生成可执行文件
add_executable(ChatServer ${SRC_LIST} ${DB_LIST} ${MD_LIST} ${RD_LIST})

#连接库文件
target_link_libraries(ChatServer muduo_net muduo_base mysqlclient hiredis pthread)

