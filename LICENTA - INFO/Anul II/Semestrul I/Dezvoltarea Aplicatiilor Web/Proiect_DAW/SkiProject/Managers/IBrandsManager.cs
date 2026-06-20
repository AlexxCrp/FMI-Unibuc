using SkiProject.Entities;
using SkiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Managers
{
    public interface IBrandsManager
    {
        List<Brand> GetBrands();
        Brand GetBrandById(string id);
        void Create(BrandModel model);
        void Update(BrandModel model);
        void Delete(string id);
    }
}
