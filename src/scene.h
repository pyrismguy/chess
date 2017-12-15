#pragma once

class Scene
{
    const char *title, *author;
public:
    Scene(const char *file);
    virtual ~Scene();

    inline const char *getTitle() const { return title; }
    inline const char *getAuthor() const { return author; }
};