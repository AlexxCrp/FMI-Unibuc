using SkiProject.Entities;
using SkiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Managers
{
    public interface ISkisManager
    {
        List<Ski> GetSkis();
        List<Ski> GetSkisByBrand(string brandId);
        Ski GetSkiById(string id);
        List<MainSkiModel> GetSkisWithBrand();
        List<MainSkiModel> GetSkisWithBrandOrdered();
        void Create(SkiModel model);
        void Update(SkiModel model);
        void Delete(string id);

    }
}
