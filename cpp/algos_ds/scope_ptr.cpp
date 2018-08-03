#include <iostream>
#include <string>

template <class T>
class ScopedPtr {
    T* object_;
public:
    ScopedPtr(T* _object) : object_(_object) {}
    T* operator->() {
        return object_;
    }
    operator T() { return (*object_); }
    ~ScopedPtr() {
        delete object_;
    }
};

class Entity {
    std::string name_;
public:
    Entity(const std::string& _name) : name_(_name) {
        std::cout << "Creating " << name_ << std::endl;
    }
    Entity(const char* _name) : name_(std::string(_name)) {
        std::cout << "Creating " << name_ << std::endl;
    }
    Entity(const Entity& _other) : name_(_other.name_) {
        std::cout << "Copying " << name_ << std::endl;
    }
    std::string say_hi() const {
        return std::string("Hello my name is ") + name_;
    }
    operator std::string() const { return name_; };
    ~Entity() {
        std::cout << "Destroying " << name_ << std::endl;
    }
};

std::ostream& operator<<(std::ostream& _stream, const Entity& _entity) {
    _stream << _entity.say_hi();
    return _stream;
}

size_t ent_size(Entity _ent) {
    return std::string(_ent).size();
}

int main() {

    ScopedPtr<Entity> akash = new Entity("Akash");
    std::cout << akash << std::endl;

}
