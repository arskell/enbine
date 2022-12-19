#ifndef SQUARE_H
#define SQUARE_H

#include "triangle.h"
#include <array>

class Square : public IntersectableObject{
    Triangle _tr_1;
    Triangle _tr_2;
    public:
    Square(const Vec3& p1, 
            const Vec3& direction_x, const Vec3& direction_y, 
            const ComponentT& size_x, const ComponentT& size_y,
        std::shared_ptr<Material> material): _tr_1(material), _tr_2(material){
            
            auto vec_x = direction_x * size_x;
            auto vec_y = direction_y * size_y;

            _tr_1.set(p1, 
                      p1 + vec_x,
                      p1 + vec_y);

            auto p2 = p1 + vec_x + vec_y;

            _tr_2.set(p2 , 
                      p2 - vec_x,
                      p2 - vec_y);

        }

    IntersectionInfo get_intersection(const Ray& ray) const override {
        auto inter_1 = calc_intersection(_tr_1, ray);
        auto inter_2 = calc_intersection(_tr_2, ray);

        if(!inter_1.is_intersected && !inter_2.is_intersected){
            return inter_1;
        }

        if(inter_1.is_intersected && !inter_2.is_intersected){
            return inter_1;
        }

        if(!inter_1.is_intersected && inter_2.is_intersected){
            return inter_2;
        }

        return std::min(inter_1, inter_2, [](auto t1, auto t2){
            return t1.t < t2.t;
        });

    }
};


#endif