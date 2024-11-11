# 当flags为0-6为关节空间点动
# 当flags为100-105为笛卡尔空间工具坐标系点动 x y z r p y
# 当flags为200-205为笛卡尔空间法兰坐标系点动
# 当flags为400-405为笛卡尔空间基坐标系点动
int16 flags        # joint id
#float velocity
bool run           # run signal
bool signal        # 运动的正反方向，true:+， false:-