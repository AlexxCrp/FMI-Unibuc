using SkiProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Repositories
{
    public interface IBrandsRepository
    {
        IQueryable<Brand> GetBrandsIQueryable();
        void Create(Brand brand);
        void Update(Brand brand);
        void Delete(Brand brand);
    }
}
