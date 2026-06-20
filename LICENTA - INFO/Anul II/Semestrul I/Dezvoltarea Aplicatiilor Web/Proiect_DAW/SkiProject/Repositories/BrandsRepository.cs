using SkiProject.Entities;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Repositories
{
    public class BrandsRepository : IBrandsRepository
    {
        private SkiProjectContext db;

        public BrandsRepository(SkiProjectContext db)
        {
            this.db = db;
        }

        public IQueryable<Brand> GetBrandsIQueryable()
        {
            var brands = db.Brands;
            return brands;
        }    

        public void Create(Brand brand)
        {
            db.Brands.Add(brand);
            db.SaveChanges();
        }

        public void Update(Brand brand)
        {
            db.Brands.Update(brand);
            db.SaveChanges();
        }

        public void Delete(Brand brand)
        {
            db.Brands.Remove(brand);
            db.SaveChanges();
        }
    }
}
