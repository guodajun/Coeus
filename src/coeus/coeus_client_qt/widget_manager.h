#ifndef __WIDGET_MANAGER_H__
#define __WIDGET_MANAGER_H__

/*
#define WIDGET_DEFINE(obj_type, func_name) \
    private: static obj_type* _m_##func_name;               \
    public:                                                 \
    static obj_type* func_name(QWidget* parent = nullptr)   \
    {                                                       \
        return tryInit<obj_type>(_m_##func_name, parent);   \
    }                                                       \
    static obj_type* relloc_##func_name(QWidget* parent = nullptr) \
    {                                                       \
        destroy_##func_name();                              \
        return func_name(parent);                           \
    }                                                       \
    static void destroy_##func_name()                       \
    {                                                       \
        SAFE_DELETE(_m_##func_name);                        \
    }

#define WIDGET_DESTROY(func_name) \
    destroy_##func_name()

#define WIDGET_STATIC_INIT(obj_type, func_name) \
    obj_type* WidgetManager::_m_##func_name = nullptr
*/

#include "venus_net/singleton.h"
#include <QWidget>

class GameLogin;
class GameSetting;
class GameCharacterCreator;
class GameMain;

class WidgetManager : public Venus::Singleton<WidgetManager>
{
public:
    WidgetManager()
        : _gameLogin(nullptr), 
        _gameSetting(nullptr),
        _gameCharacterCreator(nullptr),
        _gameMain(nullptr)
    {
    }

    virtual ~WidgetManager()
    {
        //SAFE_DELETE(_gameLogin);
        //SAFE_DELETE(_gameSetting);
    }

private:
    template <typename T>
    T* tryInit(T*& object, QWidget* parent = nullptr)
    {
        if (object == nullptr)
        {
            object = new T(parent);
        }

        return object;
    }

public:
    GameLogin* gameLogin(QWidget* parent = nullptr);
    GameSetting* gameSetting(QWidget* parent = nullptr);
    GameCharacterCreator* gameCharacterCreator(QWidget* parent = nullptr);
    GameMain* gameMain(QWidget* parent = nullptr);

private:
    GameLogin*   _gameLogin;
    GameSetting* _gameSetting;
    GameCharacterCreator* _gameCharacterCreator;
    GameMain* _gameMain;
};

#endif // !__WIDGET_MANAGER_H__
